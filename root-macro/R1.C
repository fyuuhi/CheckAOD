int R1()
{
  TH1D *deltaR = new TH1D("deltaR","title",500,0,1.0);
  tree->Draw("muon_R>>deltaR");
  deltaR->SetTitle("delta R;delta R;Number of events");

  gPad->Update();

  TPaveStats *st1 = (TPaveStats*) deltaR->FindObject("stats");
  st1->SetX1NDC(0.7);
  st1->SetX2NDC(0.9);
  st1->SetY1NDC(0.8);
  st1->SetY2NDC(1.0);

  deltaR->Draw();


  return 0;

}
