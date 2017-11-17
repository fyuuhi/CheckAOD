int RootMacro()
{
  // TCanvas *c1 = new TCanvas("c1","MyCanvas",10,10,400,400);
  //TH2F *frame = gPad->DrawFrame(0,1000,-8,2);



  TFile *_file0 = TFile::Open("run/output/hist-mc15_13TeV.361107.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zmumu.merge.AOD.e3601_s2945_r8148_r7676.root");
  tree->Draw("muonPt");

  // tree->Draw("(1/muonPt-1/(abs(L2SAPt*1000)))/(1/muonPt):muonPt/1000","abs(muon_eta)<1.1","COLZ");

  // htemp->SetTitle("s");
  // eta_barrel->SetTitle("SS");

  // TH2F *eta_barrel = (TH2F*)gROOT->FindObject("eta_barrel"),;
  
  // TH2F *eta_barrel = new TH2F(gROOT->FindObject("eta_barrel"));

  //eta_barrel->SetTitle("muonPt residual;muonPt (GeV) ;number of events");

  // eta_barrel->GetXaxis()->GetXmin(0.0);
  //eta_barrel->GetXaxis()->GetXmax(1200.0);
  //eta_barrel->GetYaxis()->GetYmin(-8.0);
  //eta_barrel->GetYaxis()->GetYmax(2.0);
  // eta_barrel->GetXaxis()->SetRangeUser(0.0,1200);
  // eta_barrel->Draw("COLZ");

  return 0;
}
