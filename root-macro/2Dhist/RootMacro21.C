int RootMacro21()
{
  TH2D *muon= new TH2D("muon","title",50,-3.5,3.5,50,-5,5);
  tree->Draw("sAddress:muon_phi>>muon","abs(muon_eta)<1.05");
  muon->SetTitle("'offline muon phi' vs 'sAddress';muon_phi;sAddress");

  gPad->Update();

  TPaveStats *st1 = (TPaveStats*) muon->FindObject("stats");
  st1->SetX1NDC(0.7);
  st1->SetX2NDC(0.9);
  st1->SetY1NDC(0.8);
  st1->SetY2NDC(1.0);

  muon->Draw("COLZ");

  return 0;

}
