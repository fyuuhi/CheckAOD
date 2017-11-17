int residual_eta_matome()
{


  TCanvas *cc = new TCanvas("cc","cc");
  cc -> Divide(2,2);


  ///barrel
  cc -> cd(3);

  TH1D *hist_b = new TH1D("hist_b","title",40,-10,10);
  tree -> Draw("(1/muonPt-1/(abs(L2SAPt*1000)))/(1/muonPt) >> hist_b","abs(muon_eta)<1.05 && sqrt(muon_R)<0.1");
  hist_b -> SetTitle("muonPt residual (barrel);muon residual;Number of events");
  
  gPad -> Update();
  
  TPaveStats *stb = (TPaveStats*) hist_b -> FindObject("stats");
  stb -> SetX1NDC(0.7);
  stb -> SetX2NDC(0.9);
  stb -> SetY1NDC(0.8);
  stb -> SetY2NDC(1.0);

  hist_b -> Draw();


  ///endcap
  cc -> cd (4);

  TH1D *hist_e = new TH1D("hist_e","title",40,-10,10);
  tree -> Draw("(1/muonPt-1/(abs(L2SAPt*1000)))/(1/muonPt) >> hist_e","abs(muon_eta)>1.05 && sqrt(muon_R)<0.1");
  hist_e -> SetTitle("muonPt residual (endcap);muon residual;Number of events");

  gPad -> Update();

  TPaveStats *ste = (TPaveStats*) hist_e -> FindObject("stats");
  ste -> SetX1NDC(0.7);
  ste -> SetX2NDC(0.9);
  ste -> SetY1NDC(0.8);
  ste -> SetY2NDC(1.0);

  hist_e -> Draw();


  ///nocut
  cc -> cd(1);

  TH1D *hist_n = new TH1D("hist_n","title",40,-10,10);
  tree -> Draw("(1/muonPt-1/(abs(L2SAPt*1000)))/(1/muonPt) >> hist_n","sqrt(muon_R)<0.1");
  hist_n -> SetTitle("muonPt residual;muon residual;Number of events");

  gPad -> Update();

  TPaveStats *stn = (TPaveStats*) hist_n -> FindObject("stats");
  stn -> SetX1NDC(0.7);
  stn -> SetX2NDC(0.9);
  stn -> SetY1NDC(0.8);
  stn -> SetY2NDC(1.0);

  hist_n -> Draw();


  return 0;
}
