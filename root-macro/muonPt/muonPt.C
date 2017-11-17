int muonPt()
{
  TH1D *hist = new TH1D("hist","title",40,-100,100);
  tree->Draw("L2SAPt>>hist");
  hist->SetTitle("muonPt;muonPt (GeV);Number of events");

  gPad->Update();

  TPaveStats *st1 = (TPaveStats*) hist->FindObject("stats");
  st1->SetX1NDC(0.7);
  st1->SetX2NDC(0.9);
  st1->SetY1NDC(0.8);
  st1->SetY2NDC(1.0);

  hist->Draw();

  return 0;

}
