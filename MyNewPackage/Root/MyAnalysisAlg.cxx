#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <MyNewPackage/MyAnalysisAlg.h>
#include <xAODEventInfo/EventInfo.h>
#include "AsgTools/MessageCheck.h"
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODMuon/MuonSegmentContainer.h"
#include "xAODTrigMuon/L2StandAloneMuonContainer.h"
#include <TSystem.h>
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
#include <TH1.h>
#include <TTree.h>
#include <cmath>

using namespace std;

//EDM include(s):
#include "AthLinks/DataLink.h"
#include "AthLinks/ElementLink.h"
#include "AthLinks/ElementLinkVector.h"

// this is needed to distribute the algorithm to the workers
//

//(http://epp.phys.kyushu-u.ac.jp/~oda/pukiwiki/index.php?xAOD%B2%F2%C0%CF2014#o027ed25) --->>> about invariant mass


ClassImp(MyAnalysisAlg)


MyAnalysisAlg :: MyAnalysisAlg ()
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().
}



EL::StatusCode MyAnalysisAlg :: setupJob (EL::Job& job)
{
  job.useXAOD();
  ANA_CHECK( xAOD::Init() );
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyAnalysisAlg :: histInitialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.

  ///TTree
  m_tree = new TTree("tree", "tree");

  wk() -> addOutput(m_tree);
  //histogram
  m_h1muonPt = new TH1D("h1_muonPt","h1_muonPt;p_{T} MeV;events", 20, 0, 100e3);
  wk() -> addOutput( m_h1muonPt );

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyAnalysisAlg :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyAnalysisAlg :: changeInput (bool firstFile)
{
  firstFile = 0;
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyAnalysisAlg :: initialize ()
{
  xAOD::TEvent* event = wk()->xaodEvent();
  Info("initialize()", "Number of events = %lli", event->getEntries() );
  m_grl = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");
  // const char* GRLFilePath = "$ROOTCOREBIN/data/MyNewPackage/data16_13TeV.periodAllYear_DetStatus-v89-pro21-01_DQDefects-00-02-04_PHYS_StandardGRL_All_Good.xml"; 
  // const char* fullGRLFilePath = gSystem->ExpandPathName (GRLFilePath);
  std::vector<std::string> vecStringGRL;
  // vecStringGRL.push_back(fullGRLFilePath);
  // ANA_CHECK(m_grl->setProperty( "GoodRunsListVec", vecStringGRL));
  ANA_CHECK(m_grl->setProperty("PassThrough", false));
  ANA_CHECK(m_grl->initialize());

  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.
  return EL::StatusCode::SUCCESS;
}


EL::StatusCode MyAnalysisAlg :: execute ()
{

  xAOD::TEvent* event = wk()->xaodEvent();
  const xAOD::EventInfo* eventInfo = 0;
  ANA_CHECK(event->retrieve(eventInfo, "EventInfo"));
  int runNumber = eventInfo->runNumber();
  int eventNumber = eventInfo->eventNumber();
  int lumiBlock = eventInfo->lumiBlock();
  int mu = eventInfo->averageInteractionsPerCrossing();
  //Info("execute()", "[[Run = %i]] :[[ Event = %i]]", runNumber, eventNumber);


  // const xAOD::MuonContainer* muons = 0; //// Container for offline muon
  // ANA_CHECK( event -> retrieve( muons, "Muons") );
  // xAOD::MuonContainer::const_iterator muon_end = muons -> end();
  // for( xAOD::MuonContainer::const_iterator muon = muons -> begin() ; muon != muon_end; muon++ ) //// iterate over container
  //   Info( "execute()", "Offline Muon Pt = %4.2f MeV", (*muon) -> pt() );


  const xAOD::L2StandAloneMuonContainer* l2saMuons = 0;
  int iL2MuonSA = 0;
  ANA_CHECK( event -> retrieve( l2saMuons, "HLT_xAOD__L2StandAloneMuonContainer_MuonL2SAInfo" ) );
  int nL2MuonSA = l2saMuons->size();
  for( auto l2saMuon : *l2saMuons ){ //// brief description
    iL2MuonSA += 1;
    //if ( l2saMuon -> algoId() != 1 ) continue; //// choose only muon algorithm id
    cout << "" << endl;
    cout << "EVENT INFO: " << Form("[Run = %i] :[Event = %i]:[LumiBlock = %i] :[<mu> = %d]: [ L2MuonSA = %i / %i ]", runNumber, eventNumber, lumiBlock, mu, iL2MuonSA, nL2MuonSA) << endl;
    //Info( "execute()", "L2SA Muon Pt = %4.2f GeV", l2saMuon -> pt() );

    // cout some variables
    cout << "pt() =" << l2saMuon -> pt()
      << ", eta() = " << l2saMuon -> eta()
      << ", phi() = " << l2saMuon -> phi()
      << endl;
    // cout << "m() = "             << l2saMuon -> m()             << endl;
    // cout << "e() = "             << l2saMuon -> e()             << endl;
    // cout << "rapidity() = "      << l2saMuon -> rapidity()      << endl;
    // cout << "roiWord() = "       << l2saMuon -> roiWord()       << endl;
    cout << "sAddress() = "      << l2saMuon -> sAddress()      << endl;
    // cout << "etaMS() = "         << l2saMuon -> etaMS()         << endl;
    // cout << "phiMS() = "         << l2saMuon -> phiMS()         << endl;
    // cout << "dirPhiMS() = "      << l2saMuon -> dirPhiMS()      << endl;
    // cout << "rMS() = "           << l2saMuon -> rMS()           << endl;
    // cout << "zMS() = "           << l2saMuon -> zMS()           << endl;
    // cout << "beta() = "          << l2saMuon -> beta()          << endl;
    // cout << "barrelRadius() = "  << l2saMuon -> barrelRadius()  << endl;
    // cout << "barrelSagitta() = " << l2saMuon -> barrelSagitta() << endl;
    // cout << "endcapAlpha() = "   << l2saMuon -> endcapAlpha()   << endl;
    // cout << "endcapAlpha() = "   << l2saMuon -> endcapAlpha()   << endl;
    // cout << "endcapBeta() = "    << l2saMuon -> endcapBeta()    << endl;
    // cout << "endcapRadius() = "  << l2saMuon -> endcapRadius()  << endl;
    // cout << "etaMap() = "        << l2saMuon -> etaMap()        << endl;
    // cout << "phiMap() = "        << l2saMuon -> phiMap()        << endl;
    // cout << "etaBin() = "        << l2saMuon -> etaBin()        << endl;
    // cout << "phiBin() = "        << l2saMuon -> phiBin()        << endl;
    cout << "isTgcFailure() = "  << l2saMuon -> isTgcFailure()  << endl;
    cout << "isRpcFailure() = "  << l2saMuon -> isRpcFailure()  << endl;
    // cout << "deltaPt() = "       << l2saMuon -> deltaPt()       << endl;
    // cout << "deltaPtParm1() = "  << l2saMuon -> deltaPtParm1()  << endl;
    // cout << "deltaPtParm2() = "  << l2saMuon -> deltaPtParm2()  << endl;
    // cout << "deltaPtParm3() = "  << l2saMuon -> deltaPtParm3()  << endl;
    // cout << "deltaEta() = "      << l2saMuon -> deltaEta()      << endl;
    // cout << "deltaPhi() = "      << l2saMuon -> deltaPhi()      << endl;
    for (int i_station = 0; i_station < 9; i_station++){
      cout << "SP: station = " << i_station
        << ", superPointR = " << l2saMuon -> superPointR(i_station)
        << ", superPointZ = " << l2saMuon -> superPointZ(i_station)
        << ", superPointSlope = " << l2saMuon -> superPointSlope(i_station)
        << ", superPointIntercept = " << l2saMuon -> superPointIntercept(i_station)
        << ", superPointChi2 = " << l2saMuon -> superPointChi2(i_station) << endl;
    }
    cout << "roiEta() = " << l2saMuon -> roiEta() << endl;
    cout << "roiPhi() = " << l2saMuon -> roiPhi() << endl;
    for (int i_station = 0; i_station < 9; i_station++){
      cout << "Road: station = " << i_station
        << ", chamberType1 = " << l2saMuon -> chamberType1(i_station, 0)
        << ", chamberType2 = " << l2saMuon -> chamberType2(i_station, 0)
        << ", roadAw = " << l2saMuon -> roadAw(i_station, 0)
        << ", roadBw = " << l2saMuon -> roadBw(i_station, 0)
        << ", zMin = " << l2saMuon -> zMin(i_station, 0)
        << ", zMax = " << l2saMuon -> zMax(i_station, 0)
        << ", etaMin = " << l2saMuon -> etaMin(i_station, 0)
        << ", etaMax = " << l2saMuon -> etaMax(i_station, 0) << endl;
    }
    cout << "nRpcHits = " << (l2saMuon->rpcHitX()).size() << endl;
    cout << "nMdtHits = " << l2saMuon->nMdtHits() << endl;
    for (uint32_t iMdtHit = 0; iMdtHit < l2saMuon->nMdtHits(); iMdtHit++){
      cout << "Mdt[" << iMdtHit << "]"
        << ", mdtHitIsOutlier = " << l2saMuon -> mdtHitIsOutlier(iMdtHit)
        << ", mdtHitChamber = " << l2saMuon -> mdtHitChamber(iMdtHit)
        << ", mdtHitR = " << l2saMuon -> mdtHitR(iMdtHit)
        << ", mdtHitZ = " << l2saMuon -> mdtHitZ(iMdtHit)
        << ", mdtHitPhi = " << l2saMuon -> mdtHitPhi(iMdtHit)
        << ", mdtHitResidual = " << l2saMuon -> mdtHitResidual(iMdtHit)
        << ", mdtHitTime = " << l2saMuon -> mdtHitTime(iMdtHit)
        << ", mdtHitSpace = " << l2saMuon -> mdtHitSpace(iMdtHit)
        << ", mdtHitSigma = " << l2saMuon -> mdtHitSigma(iMdtHit) << endl;
    }
  }

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyAnalysisAlg :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyAnalysisAlg :: finalize ()
{
  cout << "" << endl;
  cout << "MyAnalysisAlg::finalize()" << endl;
  cout << "" << endl;
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyAnalysisAlg :: histFinalize ()
{
  // This method is the mirror image of histInitialize(), meaning it
  // gets called after the last event has been processed on the worker
  // node and allows you to finish up any objects you created in
  // histInitialize() before they are written to disk.  This is
  // actually fairly rare, since this happens separately for each
  // worker node.  Most of the time you want to do your
  // post-processing on the submission node after all your histogram
  // outputs have been merged.  This is different from finalize() in
  // that it gets called on all worker nodes regardless of whether
  // they processed input events.
  return EL::StatusCode::SUCCESS;
}
