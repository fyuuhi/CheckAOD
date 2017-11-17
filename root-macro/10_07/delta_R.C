int delta_R()
{
  TCanvas *cc = new TCanvas("cc","cc"); 
  cc ->Divide(2,2);

  cc->cd(1);


  TH1D *deltaR = new TH1D("deltaR","title",500,0,0.6);
  tree->Draw("muon_R>>deltaR");
  deltaR->SetTitle("delta R;delta R;Number of events");

  gPad->Update();

  deltaR->GetXaxis()->SetTitleOffset(1.0);
  deltaR->GetYaxis()->SetTitleOffset(1.5);

  TPaveStats *st1 = (TPaveStats*) deltaR->FindObject("stats");
  st1->SetX1NDC(0.7);
  st1->SetX2NDC(0.9);
  st1->SetY1NDC(0.8);
  st1->SetY2NDC(1.0);

  deltaR->Draw();

  cc->cd(2);

  TH1D *dR = new TH1D("dR","title",500,0,0.6);
  tree->Draw("muon_R>>dR","charge == charge_SA");
  dR->SetTitle("delta R;delta R;Number of events");

  gPad->Update();

  dR->GetXaxis()->SetTitleOffset(1.0);
  dR->GetYaxis()->SetTitleOffset(1.5);

  TPaveStats *st2 = (TPaveStats*) dR->FindObject("stats");
  st2->SetX1NDC(0.7);
  st2->SetX2NDC(0.9);
  st2->SetY1NDC(0.8);
  st2->SetY2NDC(1.0);

  dR->Draw();


  cc->cd(3);

  TH1D *dR1 = new TH1D("dR1","title",500,0,0.6);
  tree->Draw("muon_R>>dR1","muon_R < 0.1");
  dR1->SetTitle("delta R;delta R;Number of events");

  gPad->Update();

  dR1->GetXaxis()->SetTitleOffset(1.0);
  dR1->GetYaxis()->SetTitleOffset(1.5);

  TPaveStats *st3 = (TPaveStats*) dR1->FindObject("stats");
  st3->SetX1NDC(0.7);
  st3->SetX2NDC(0.9);
  st3->SetY1NDC(0.8);
  st3->SetY2NDC(1.0);

  dR1->Draw();


  cc->cd(4);

  TH1D *dR2 = new TH1D("dR2","title",500,0,0.6);
  tree->Draw("muon_R>>dR2","charge == charge_SA && muon_R < 0.1");
  dR2->SetTitle("delta R;delta R;Number of events");

  gPad->Update();

  dR2->GetXaxis()->SetTitleOffset(1.0);
  dR2->GetYaxis()->SetTitleOffset(1.5);

  TPaveStats *st4 = (TPaveStats*) dR2->FindObject("stats");
  st4->SetX1NDC(0.7);
  st4->SetX2NDC(0.9);
  st4->SetY1NDC(0.8);
  st4->SetY2NDC(1.0);

  dR2->Draw();

  return 0;

}
