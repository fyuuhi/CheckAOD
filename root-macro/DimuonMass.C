int DimuonMass()
{
  TH1D *histgram = new TH1D("histgram","title",200,2.6,3.6);
  tree->Draw("dimuon_mass/1000>>histgram","(highPtPos > 0 && highPtNeg > 0 && dimuon_mass > 0) && (quality == 0 || quality == 1)");
  histgram->SetTitle("invariant mass of dimuon;invariant mass (GeV);Number of events");

  histgram -> Draw();

  TF1 *f = new TF1("f","[0]/((pow(x-[1],2.0))+pow([2]/2,2))",0,9);
  f -> SetParameter(0,0.5);
  f -> SetParameter(1,3.);
  f -> SetParameter(2,2.);

  histgram -> Fit("f","","",2,4.5);

  gPad->Update();

  TPaveStats *st1 = (TPaveStats*) histgram->FindObject("stats");
  st1->SetX1NDC(0.7);
  st1->SetX2NDC(0.9);
  st1->SetY1NDC(0.8);
  st1->SetY2NDC(1.0);

//  histgram->Draw();

  return 0;

}
