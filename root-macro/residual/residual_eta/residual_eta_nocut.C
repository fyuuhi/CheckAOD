int residual_eta_nocut()
{
  TH1D *hist = new TH1D("hist","title",40,-10,10);
  tree -> Draw("(1/muonPt-1/(abs(L2SAPt*1000)))/(1/muonPt) >> hist","sqrt(muon_R)<0.1");
  hist -> SetTitle("muonPt residual;muon residual;Number of events");
  
  gPad -> Update();
 /* 
  TPaveStats *st1 = (TPaveStats*) hist -> FindObject("stats");
  st1 -> SetX1NDC(0.7);
  st1 -> SetX1NDC(0.9);
  st1 -> SetX1NDC(0.8);
  st1 -> SetX1NDC(1.0);
*/
  hist -> Draw();

  return 0;
}
