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
