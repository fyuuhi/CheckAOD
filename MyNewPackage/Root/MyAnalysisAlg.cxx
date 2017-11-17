#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <MyNewPackage/MyAnalysisAlg.h>
#include <xAODEventInfo/EventInfo.h>
#include "AsgTools/MessageCheck.h"
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTrigMuon/L2StandAloneMuonContainer.h"
#include <TSystem.h>
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
#include <TH1.h>
#include <TTree.h>
#include <cmath>
// this is needed to distribute the algorithm to the workers

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
  m_muonPt = new std::vector< Double_t >;
  m_real_muonPt = new std::vector< Double_t >;
  m_L2SAPt = new std::vector< Double_t >;
  m_real_L2SAPt = new std::vector< Double_t >;
  m_muon_eta = new std::vector< Double_t >;
  m_muon_phi = new std::vector< Double_t >;
  m_muon_e = new std::vector< Double_t >;
  m_muon_R = new std::vector<Double_t >;
  m_PosR = new std::vector<Double_t >;
  m_NegR = new std::vector<Double_t >;
  m_muon_residual = new std::vector< Double_t >;
  m_L2SA_eta = new std::vector< Double_t >;
  m_L2SA_phi = new std::vector< Double_t >;
  m_L2SA_e = new std::vector< Double_t >;
  m_L2SA_m = new std::vector< Double_t >;
  m_charge = new std::vector< Double_t >;
  m_charge_SA = new std::vector< Double_t >;
  m_dimuon_mass = new std::vector< Double_t >;
  m_sAddress = new std::vector< Double_t>;
  m_highPtPos = new std::vector< Double_t >;
  m_highPtNeg = new std::vector< Double_t >;
  m_etaMS = new std::vector< Double_t >;
  m_phiMS = new std::vector< Double_t >;
  m_quality = new std::vector< Double_t >;
  //
  m_tgcpt = new std::vector< Double_t >;
  m_ptBarrelRadius = new std::vector< Double_t >;
  m_ptBarrelSagitta = new std::vector< Double_t >;
  m_ptEndcapAlpha = new std::vector< Double_t >;
  m_ptEndcapBeta = new std::vector< Double_t >;
  m_ptEndcapRadius = new std::vector< Double_t >;
  m_ptCSC = new std::vector< Double_t >;
  // 
  m_max_R = new std::vector< Double_t >;
  m_min_R = new std::vector< Double_t >;
  m_L2SA_p4 = new std::vector< Double_t >;
  m_L2SA_mass = new std::vector< Double_t >;


  m_l2_eta = new std::vector<Double_t>;
  m_l2_phi = new std::vector<Double_t>;
  m_l2_R = new std::vector<Double_t>;
  m_l2_pt = new std::vector<Double_t>;



  m_tree -> Branch("muonPt",&m_muonPt);
  m_tree -> Branch("real_muonPt",&m_real_muonPt);
  m_tree -> Branch("L2SAPt",&m_L2SAPt);
  m_tree -> Branch("real_L2SAPt",&m_real_L2SAPt);
  m_tree -> Branch("muon_eta",&m_muon_eta);
  m_tree -> Branch("muon_phi",&m_muon_phi);
  m_tree -> Branch("muon_e",&m_muon_e);
  m_tree -> Branch("muon_R",&m_muon_R);
  m_tree -> Branch("PosR",&m_PosR);
  m_tree -> Branch("NegR",&m_NegR);
  m_tree -> Branch("muon_residual",&m_muon_residual);
  m_tree -> Branch("L2SA_eta",&m_L2SA_eta); 
  m_tree -> Branch("L2SA_phi",&m_L2SA_phi);
  m_tree -> Branch("L2SA_e",&m_L2SA_e);
  m_tree -> Branch("L2SA_m",&m_L2SA_m);
  m_tree -> Branch("charge",&m_charge);
  m_tree -> Branch("charge_SA",&m_charge_SA);
  m_tree -> Branch("dimuon_mass",&m_dimuon_mass);
  m_tree -> Branch("sAddress",&m_sAddress);
  m_tree -> Branch("highPtPos",&m_highPtPos);
  m_tree -> Branch("highPtNeg",&m_highPtNeg);
  m_tree -> Branch("etaMS",&m_etaMS);
  m_tree -> Branch("phiMS",&m_phiMS);
  m_tree -> Branch("quality",&m_quality);
  //
  m_tree -> Branch("tgcpt",&m_tgcpt);
  m_tree -> Branch("ptBarrelRadius",&m_ptBarrelRadius);
  m_tree -> Branch("ptBarrelSagitta",&m_ptBarrelSagitta);
  m_tree -> Branch("ptEndcapAlpha",&m_ptEndcapAlpha);
  m_tree -> Branch("ptEndcapBeta",&m_ptEndcapBeta);
  m_tree -> Branch("ptEndcapRadius",&m_ptEndcapRadius);
  m_tree -> Branch("ptCSC",&m_ptCSC);
  //

  m_tree -> Branch("max_R",&m_max_R);
  m_tree -> Branch("min_R",&m_min_R);
  m_tree -> Branch("L2SA_p4",&m_L2SA_p4);
  m_tree -> Branch("L2SA_mass",&m_L2SA_mass);

  m_tree -> Branch("l2_eta",&m_l2_eta);
  m_tree -> Branch("l2_phi",&m_l2_phi);
  m_tree -> Branch("l2_pt",&m_l2_pt);
  m_tree -> Branch("l2_R",&m_l2_R);




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
  const char* GRLFilePath = "$ROOTCOREBIN/data/MyNewPackage/data16_13TeV.periodAllYear_DetStatus-v89-pro21-01_DQDefects-00-02-04_PHYS_StandardGRL_All_Good.xml"; 
  const char* fullGRLFilePath = gSystem->ExpandPathName (GRLFilePath);
  std::vector<std::string> vecStringGRL;
  vecStringGRL.push_back(fullGRLFilePath);
  ANA_CHECK(m_grl->setProperty( "GoodRunsListVec", vecStringGRL));
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
  m_muonPt -> clear();
  m_real_muonPt -> clear();
  m_L2SAPt -> clear();
  m_real_L2SAPt -> clear();
  m_muon_eta -> clear(); 
  m_muon_phi -> clear();
  m_muon_e -> clear();
  m_muon_R -> clear();
  m_PosR -> clear();
  m_NegR -> clear();
  m_muon_residual -> clear();
  m_L2SA_eta -> clear(); 
  m_L2SA_phi -> clear();
  m_L2SA_e -> clear();
  m_L2SA_m -> clear();
  m_charge -> clear();
  m_charge_SA -> clear();
  m_dimuon_mass -> clear();
  m_sAddress -> clear();
  m_highPtPos -> clear();
  m_highPtNeg -> clear();
  m_etaMS -> clear();
  m_phiMS -> clear();
  m_quality -> clear();
  //
  m_tgcpt -> clear();
  m_ptBarrelRadius -> clear();
  m_ptBarrelSagitta -> clear();
  m_ptEndcapAlpha -> clear();
  m_ptEndcapBeta -> clear();
  m_ptEndcapRadius -> clear();
  m_ptCSC -> clear();
  //
  m_max_R -> clear();
  m_min_R -> clear();
  m_L2SA_p4 -> clear();
  m_L2SA_mass -> clear();

  m_l2_pt -> clear();
  m_l2_R -> clear();
  m_l2_eta -> clear();
  m_l2_phi -> clear();





  xAOD::TEvent* event = wk()->xaodEvent();
  const xAOD::EventInfo* eventInfo = 0;
  ANA_CHECK(event->retrieve(eventInfo, "EventInfo"));
  int runNumber = eventInfo->runNumber();
  int eventNumber = eventInfo->eventNumber();
  Info("execute()", "[[Run = %i]] :[[ Event = %i]]", runNumber, eventNumber);


  const xAOD::MuonContainer* muons = 0; //// Container for offline muon
  ANA_CHECK( event -> retrieve( muons, "Muons") );
  xAOD::MuonContainer::const_iterator muon_end = muons -> end();
  for( xAOD::MuonContainer::const_iterator muon = muons -> begin() ; muon != muon_end; muon++ ) //// iterate over container
    Info( "execute()", "Offline Muon Pt = %4.2f MeV", (*muon) -> pt() );


  const xAOD::L2StandAloneMuonContainer* l2saMuons = 0;
  ANA_CHECK( event -> retrieve( l2saMuons, "HLT_xAOD__L2StandAloneMuonContainer_MuonL2SAInfo" ) );
  for( auto l2saMuon : *l2saMuons ){ //// brief description
    if ( l2saMuon -> algoId() != 1 ) continue; //// choose only muon algorithm id
    Info( "execute()", "L2SA Muon Pt = %4.2f GeV", l2saMuon -> pt() ); //// be careful of GeV( not MeV as usual ) and sign of pt means charge
  }


  //// Retrieve eventInfo above
  bool isMC = false;
  if ( eventInfo -> eventType( xAOD::EventInfo::IS_SIMULATION ) )
    isMC = true;
  if( !isMC ){
    if( !m_grl -> passRunLB( *eventInfo ) ){ Info( "execute()", "GRL not pass RunLB"); return EL::StatusCode::SUCCESS;
    } }

  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.
  //const xAOD::MuonContainer* muons = 0;
  //ANA_CHECK( event -> retrieve( muons, "Muons") ); 

  const xAOD::Muon* highPtPosMuon = 0; // add (09/20) 
  const xAOD::Muon* highPtNegMuon = 0; // add (09/20)  
  const xAOD::Muon* real_muon = 0; // add (09/20) 
  const xAOD::L2StandAloneMuonContainer* real_L2SA = 0; // add (09/20) 

  std::vector<Double_t> m_Real;
  std::vector<Double_t> m_L2_phi;
  std::vector<Double_t> m_L2_eta;
  std::vector<Double_t> m_L2_R;
  std::vector<Double_t> m_L2_pt;
  std::vector<Double_t> m_L2_sAddress;
  std::vector<Double_t> m_L2_phiMS;
  std::vector<Double_t> m_L2_etaMS;
  //
  std::vector<Double_t> m_L2_tgcpt;
  std::vector<Double_t> m_L2_ptBarrelRadius;
  std::vector<Double_t> m_L2_ptBarrelSagitta;
  std::vector<Double_t> m_L2_ptEndcapAlpha;
  std::vector<Double_t> m_L2_ptEndcapBeta;
  std::vector<Double_t> m_L2_ptEndcapRadius;
  std::vector<Double_t> m_L2_ptCSC;
  //

  Double_t min_1 = 999.;
  Double_t min_2 = 9999.;


  for( auto muon : *muons ) {//=========muon Loop starts==========

    Info( "execute()", "--Offline Muon Pt = %4.2f MeV--", muon -> pt() ); //// Fill and push_back variables
    m_h1muonPt -> Fill( muon -> pt() );

    //real_muon = muon;
    // m_real_muonPt -> push_back(real_muon -> pt() );
    // m_muon_eta -> push_back( muon -> eta() );
    // m_muon_phi -> push_back( muon -> phi() );
    // m_muon_e -> push_back( muon -> e() );
    // m_charge -> push_back( muon -> charge() );
    // m_quality -> push_back( muon -> quality() );   

    for( auto l2saMuon : *l2saMuons ){
      //===================l2saMuon Loop starts (in muon Loop)===============

      if(std::abs(l2saMuon -> pt()) > 0.  && std::abs(l2saMuon -> eta()) > 0. && std::abs(l2saMuon -> phi()) > 0. && std::abs(muon -> pt()) > 0. && std::abs(muon -> eta()) > 0.&& std::abs(muon -> phi()) > 0. ) {

        m_L2_R.push_back( std::sqrt( std::pow( ( muon -> eta() - l2saMuon -> eta() ),2.0)+std::pow( ( muon -> phi() - l2saMuon -> phi() ),2.0)));
        m_L2_eta.push_back(l2saMuon -> eta());
        m_L2_phi.push_back(l2saMuon -> phi());
        m_L2_pt.push_back(l2saMuon -> pt());
        m_L2_sAddress.push_back(l2saMuon -> sAddress());
        m_L2_phiMS.push_back(l2saMuon -> phiMS());
        m_L2_etaMS.push_back(l2saMuon -> etaMS());
        m_Real.push_back(muon -> pt());
        //
        m_L2_tgcpt.push_back(l2saMuon -> tgcPt());
        m_L2_ptBarrelRadius.push_back(l2saMuon -> ptBarrelRadius());
        m_L2_ptBarrelSagitta.push_back(l2saMuon -> ptBarrelSagitta());
        m_L2_ptEndcapAlpha.push_back(l2saMuon -> ptEndcapAlpha());
        m_L2_ptEndcapBeta.push_back(l2saMuon -> ptEndcapBeta());
        m_L2_ptEndcapRadius.push_back(l2saMuon -> ptEndcapRadius());
        m_L2_ptCSC.push_back(l2saMuon -> ptCSC());
        //
      }
    }

    int l2n = m_L2_R.size();
    double m1 = 111111.0;

    for(int i = 0;i < l2n; ++i){
      if(m_L2_R.at(i) < m1){
        m1 = m_L2_R.at(i);
      }
    }

    int l2m = 0.0;

    for(int j =0;j < l2n; ++j){
      if(m1 == m_L2_R.at(j)){
        l2m = j;
      }
    }


    if(m_L2_pt.size() > 0){
      m_L2SAPt -> push_back(m_L2_pt.at(l2m));
      if(m_L2_pt.at(l2m) > 0.0){
        m_charge_SA -> push_back(1.0);
      }else if(m_L2_pt.at(l2m) < 0.0){
        m_charge_SA -> push_back(-1.0);
      }
      m_L2SA_phi -> push_back(m_L2_phi.at(l2m));
      m_L2SA_eta -> push_back(m_L2_eta.at(l2m));
      m_muon_R -> push_back(m_L2_R.at(l2m));
      m_sAddress -> push_back(m_L2_sAddress.at(l2m));
      m_etaMS -> push_back(m_L2_etaMS.at(l2m));
      m_phiMS -> push_back(m_L2_phiMS.at(l2m));
      //
      m_tgcpt->push_back(m_L2_tgcpt.at(l2m));
      m_ptBarrelRadius->push_back(m_L2_ptBarrelRadius.at(l2m));
      m_ptBarrelSagitta->push_back(m_L2_ptBarrelSagitta.at(l2m));
      m_ptEndcapAlpha->push_back(m_L2_ptEndcapAlpha.at(l2m));
      m_ptEndcapBeta->push_back(m_L2_ptEndcapBeta.at(l2m));
      m_ptEndcapRadius->push_back(m_L2_ptEndcapRadius.at(l2m));
      m_ptCSC->push_back(m_L2_ptCSC.at(l2m));
      //



      m_muonPt -> push_back(muon -> pt());
      m_muon_eta -> push_back(muon -> eta());
      m_muon_phi -> push_back(muon -> phi());
      m_quality -> push_back(muon -> quality());
      m_charge -> push_back(muon -> charge());
      m_muon_residual -> push_back(((1000.0/muon -> pt())-(1/std::abs(m_L2_pt.at(l2m))))/(1000.0/muon -> pt()));

    }else {
      m_L2SAPt -> push_back(9999.0);
      m_charge_SA -> push_back(9999.0);
      m_L2SA_phi -> push_back(9999.0);
      m_L2SA_eta -> push_back(9999.0);
      m_muon_R -> push_back(9999.0);
      m_sAddress -> push_back(9999.0);
      m_etaMS -> push_back(9999.0);
      m_phiMS -> push_back(9999.0);

      m_muonPt -> push_back(9999.0);
      m_muon_eta -> push_back(9999.0);
      m_muon_phi -> push_back(9999.0);
      m_quality -> push_back(9999.0);
      m_charge -> push_back(9999.0);
      m_muon_residual -> push_back(9999.0);
      //
      m_tgcpt->push_back(9999.0);
      m_ptBarrelRadius->push_back(9999.0);
      m_ptBarrelSagitta->push_back(9999.0);
      m_ptEndcapAlpha->push_back(9999.0);
      m_ptEndcapBeta->push_back(9999.0);
      m_ptEndcapRadius->push_back(9999.0);
      m_ptCSC->push_back(9999.0);
      //

    }



    std::vector<Double_t>().swap(m_L2_pt);
    std::vector<Double_t>().swap(m_L2_phi);
    std::vector<Double_t>().swap(m_L2_eta);
    std::vector<Double_t>().swap(m_L2_R);
    std::vector<Double_t>().swap(m_L2_sAddress);
    std::vector<Double_t>().swap(m_L2_phiMS);
    std::vector<Double_t>().swap(m_L2_etaMS);
    //
    std::vector<Double_t>().swap(m_L2_tgcpt);
    std::vector<Double_t>().swap(m_L2_ptBarrelRadius);
    std::vector<Double_t>().swap(m_L2_ptBarrelSagitta);
    std::vector<Double_t>().swap(m_L2_ptEndcapAlpha);
    std::vector<Double_t>().swap(m_L2_ptEndcapBeta);
    std::vector<Double_t>().swap(m_L2_ptEndcapRadius);
    std::vector<Double_t>().swap(m_L2_ptCSC);
    //

  }

  int mn = m_muonPt -> size(); 
  //double min_1 = 99999.0;

  for(int k = 0;k < mn;++k){

    for(int l = 0;l < mn;++l){
      if(m_L2SAPt -> at(k) == m_L2SAPt -> at(l)){
        if(m_muon_R -> at(k) < m_muon_R -> at(l)){
          m_muon_R -> at(l) = m_muon_R -> at(l) + 10000.0; 
        } 
      }
    }
  }


  //m_l2_eta = new std::vector<Doube_t>;



  m_real_muonPt -> push_back(m_Real.size());

  //m_Real -> clear();




  ////Fill tree
  m_tree -> Fill();

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
  if(m_muonPt != 0) {
    delete m_muonPt; m_muonPt = 0;
  }

  if(m_real_muonPt != 0) {
    delete m_real_muonPt; m_real_muonPt = 0;
  }

  if(m_L2SAPt != 0) {
    delete m_L2SAPt; m_L2SAPt = 0;
  }

  if(m_real_L2SAPt != 0) {
    delete m_real_L2SAPt; m_real_L2SAPt = 0;
  }

  if(m_muon_eta != 0) {
    delete m_muon_eta; m_muon_eta = 0;
  } 

  if(m_muon_phi != 0) {
    delete m_muon_phi; m_muon_phi = 0;
  }

  if(m_muon_e != 0) {
    delete m_muon_e; m_muon_e = 0; 
  } 

  if(m_muon_R != 0) {
    delete m_muon_R; m_muon_R = 0;
  }  

  if(m_PosR != 0) {
    delete m_PosR; m_PosR = 0;
  } 

  if(m_NegR != 0) {
    delete m_NegR; m_NegR = 0;
  }  

  if(m_muon_residual != 0) {
    delete m_muon_residual; m_muon_residual = 0;  
  }


  if(m_L2SA_eta != 0) {
    delete m_L2SA_eta; m_L2SA_eta = 0; 
  } 

  if(m_L2SA_phi != 0) {
    delete m_L2SA_phi; m_L2SA_phi = 0;
  }

  if(m_L2SA_e != 0) {
    delete m_L2SA_e; m_L2SA_e = 0;           
  }  

  if(m_L2SA_m != 0) {
    delete m_L2SA_m; m_L2SA_m= 0;                               
  }  

  if(m_charge != 0) {
    delete m_charge; m_charge = 0;
  }

  if(m_charge_SA != 0) {
    delete m_charge_SA; m_charge_SA = 0;
  }

  if(m_dimuon_mass != 0) {
    delete m_dimuon_mass; m_dimuon_mass = 0;
  }

  if(m_sAddress != 0) {
    delete m_sAddress; m_sAddress = 0; 
  }

  if(m_highPtPos != 0) {
    delete m_highPtPos; m_highPtPos = 0;
  }

  if(m_highPtNeg != 0) {
    delete m_highPtNeg; m_highPtNeg = 0;
  }

  if(m_etaMS != 0) {
    delete m_etaMS ; m_etaMS = 0;
  }

  if(m_phiMS != 0) {
    delete m_phiMS ; m_phiMS = 0;
  }

  //

  if(m_tgcpt != 0) {
    delete m_tgcpt ; m_tgcpt = 0;
  }
  if(m_ptBarrelRadius != 0) {
    delete m_ptBarrelRadius ; m_ptBarrelRadius = 0;
  }
  if(m_ptBarrelSagitta != 0) {
    delete m_ptBarrelSagitta ; m_ptBarrelSagitta = 0;
  }
  if(m_ptEndcapAlpha != 0) {
    delete m_ptEndcapAlpha ; m_ptEndcapAlpha = 0;
  }
  if(m_ptEndcapBeta != 0) {
    delete m_ptEndcapBeta ; m_ptEndcapBeta = 0;
  }
  if(m_ptEndcapRadius != 0) {
    delete m_ptEndcapRadius ; m_ptEndcapRadius = 0;
  }
  if(m_ptCSC != 0) {
    delete m_ptCSC ; m_ptCSC = 0;
  }
  //
  if(m_quality != 0) {
    delete m_quality ; m_quality = 0;
  }

  if(m_max_R != 0) {
    delete m_max_R ; m_max_R = 0;
  }

  if(m_min_R != 0) {
    delete m_min_R ; m_min_R = 0;
  }

  if(m_L2SA_mass != 0) {
    delete m_L2SA_mass ; m_L2SA_mass = 0;
  }

  if(m_L2SA_p4 != 0) {
    delete m_L2SA_p4 ; m_L2SA_p4 = 0;
  }

  if(m_l2_pt != 0) {
    delete m_L2SA_p4 ; m_L2SA_p4 = 0;
  }

  if(m_l2_R != 0) {
    delete m_l2_R ; m_l2_R = 0;
  }

  if(m_l2_eta != 0) {
    delete m_l2_eta ; m_l2_eta = 0;
  }

  if(m_l2_phi != 0) {
    delete m_l2_phi ; m_l2_phi = 0;
  }

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
