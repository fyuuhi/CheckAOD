int RootMacro2()
{


  TCanvas *cc = new TCanvas("cc","cc");
  cc -> Divide(3,2);

  TCut c_dR = "muon_R<0.1";
  TCut c_barrel = "abs(muon_eta)<1.05";
  TCut c_sAddress_0 = "sAddress == 0";
  TCut c_sAddress_1 = "sAddress == 1";  
  TCut c_sAddress_2 = "sAddress == 2";
  TCut c_sAddress_3 = "sAddress == 3";



// 2Dhist "sAddress:muon_residual"
cc -> cd(1);

  TH2D *muon= new TH2D("muon","title",50,-3.,2.0,30,-2,4);
  tree->Draw("sAddress:muon_residual>>muon",c_dR && c_barrel);
  muon->SetTitle("muonPt residual 2Dhist ;muon residual;sAddress");

  gPad->Update();

  TPaveStats *stn = (TPaveStats*) muon->FindObject("stats");
  stn->SetX1NDC(0.7);
  stn->SetX2NDC(0.9);
  stn->SetY1NDC(0.8);
  stn->SetY2NDC(1.0);

  muon->Draw("COLZ");


  //sAddress(0)
  cc -> cd (2);

  TH1D *hist_0 = new TH1D("hist_0","title",200,-2,2);
  tree -> Draw("muon_residual >> hist_0",c_dR && c_barrel && c_sAddress_0);
  hist_0 -> SetTitle("muonPt residual ,sAddress = 0;muon residual;Number of events");
/*

  gPad -> Update();

  TPaveStats *st0 = (TPaveStats*) hist_0 -> FindObject("stats");
  st0 -> SetX1NDC(0.7);
  st0 -> SetX2NDC(0.9);
  st0 -> SetY1NDC(0.8);
  st0 -> SetY2NDC(1.0);

*/

  hist_0 -> Draw();


  //sAddress(1)
  cc -> cd (3);

  TH1D *hist_1 = new TH1D("hist_1","title",200,-2,2);
  tree -> Draw("muon_residual >> hist_1",c_dR && c_barrel && c_sAddress_1);
  hist_1 -> SetTitle("muonPt residual ,sAddress = 1;muon residual;Number of events");
/*

  gPad -> Update();

  TPaveStats *st1 = (TPaveStats*) hist_1 -> FindObject("stats");
  st1 -> SetX1NDC(0.7);
  st1 -> SetX2NDC(0.9);
  st1 -> SetY1NDC(0.8);
  st1 -> SetY2NDC(1.0);

*/

  hist_1 -> Draw();


  //sAddress(2)
  cc -> cd (4);

  TH1D *hist_2 = new TH1D("hist_2","title",200,-2,2);
  tree -> Draw("muon_residual >> hist_2",c_dR && c_barrel && c_sAddress_2);
  hist_2 -> SetTitle("muonPt residual ,sAddress = 2;muon residual;Number of events");
/*

  gPad -> Update();

  TPaveStats *st2 = (TPaveStats*) hist_2 -> FindObject("stats");
  st2 -> SetX1NDC(0.7);
  st2 -> SetX2NDC(0.9);
  st2 -> SetY1NDC(0.8);
  st2 -> SetY2NDC(1.0);

*/

  hist_2 -> Draw();


  //sAddress(3)
  cc -> cd (5);

  TH1D *hist_3 = new TH1D("hist_3","title",200,-2,2);
  tree -> Draw("muon_residual >> hist_3",c_dR && c_barrel && c_sAddress_3);
  hist_3 -> SetTitle("muonPt residual ,sAddress = 3;muon residual;Number of events");
/*

  gPad -> Update();

  TPaveStats *st3 = (TPaveStats*) hist_3 -> FindObject("stats");
  st3 -> SetX1NDC(0.7);
  st3 -> SetX2NDC(0.9);
  st3 -> SetY1NDC(0.8);
  st3 -> SetY2NDC(1.0);

*/

  hist_3 -> Draw();

  return 0;

}
