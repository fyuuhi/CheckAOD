#ifndef MyNewPackage_MyAnalysisAlg_H
#define MyNewPackage_MyAnalysisAlg_H

#include <EventLoop/Algorithm.h>


class GoodRunsListSelectionTool;

class Th1;
class TTree;

class MyAnalysisAlg : public EL::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // float cutValue;

  GoodRunsListSelectionTool* m_grl; //!
  
  std::vector<Double_t>* m_muonPt; //! 
  std::vector<Double_t>* m_real_muonPt; //! 
  std::vector<Double_t>* m_L2SAPt; //! 
  std::vector<Double_t>* m_real_L2SAPt; //! 
  std::vector<Double_t>* m_muon_eta; //! 
  std::vector<Double_t>* m_muon_phi; //!
  std::vector<Double_t>* m_muon_e; //!
  std::vector<Double_t>* m_muon_R; //!
  std::vector<Double_t>* m_PosR; //!
  std::vector<Double_t>* m_NegR; //!
  std::vector<Double_t>* m_muon_residual; //!
  std::vector<Double_t>* m_L2SA_eta; //!
  std::vector<Double_t>* m_L2SA_phi; //!
  std::vector<Double_t>* m_L2SA_e; //!
  std::vector<Double_t>* m_L2SA_m; //!
  std::vector<Double_t>* m_charge; //!
  std::vector<Double_t>* m_charge_SA; //!
  std::vector<Double_t>* m_dimuon_mass; //!
  std::vector<Double_t>* m_sAddress; //!
  std::vector<Double_t>* m_highPtPos; //!
  std::vector<Double_t>* m_highPtNeg; //! 
  std::vector<Double_t>* m_etaMS; //!
  std::vector<Double_t>* m_phiMS; //!
  std::vector<Double_t>* m_quality; //!
//
  std::vector<Double_t>* m_tgcpt; //!
  std::vector<Double_t>* m_ptBarrelRadius; //!
  std::vector<Double_t>* m_ptBarrelSagitta; //!
  std::vector<Double_t>* m_ptEndcapAlpha; //!
  std::vector<Double_t>* m_ptEndcapBeta; //!
  std::vector<Double_t>* m_ptEndcapRadius; //!
  std::vector<Double_t>* m_ptCSC; //!
//
  std::vector<Double_t>* m_max_R; //!
  std::vector<Double_t>* m_min_R; //!
  std::vector<Double_t>* m_L2SA_p4; //!
  std::vector<Double_t>* m_L2SA_mass; //!
 
  std::vector<Double_t>* m_l2_phi; //!
  std::vector<Double_t>* m_l2_eta; //!
  std::vector<Double_t>* m_l2_pt; //!
  std::vector<Double_t>* m_l2_R; //!


  TTree* m_tree; //!
  TH1* m_h1muonPt; //!
  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  // Tree *myTree; //!
  // TH1 *myHist; //!



  // this is a standard constructor
  MyAnalysisAlg ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(MyAnalysisAlg, 1);
};

#endif
