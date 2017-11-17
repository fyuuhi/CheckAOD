
int R()
{


  TCanvas *ccpt = new TCanvas("ccpt","ccpt");
  ccpt -> Divide(2,2);

  TCut C_max_min = "muon_R == max_R || muon_R == min_R"; 
  TCut C_R = "muon_R < 0.1";
  TCut C_charge = "charge == charge_SA";
  TCut C_barrel = "abs(muon_eta) < 1.05"; 
  TCut C_endcap = "abs(muon_eta) < 1.05"; 
  TCut C_tight = "quality == 0"; 
  TCut C_middle = "quality == 1"; 




  //muon_R 1DHist
  ccpt -> cd(1);

  TH1D *hist1 = new TH1D("hist1","title",100,0,1);
  tree -> Draw("muon_R >> hist1", C_R && C_max_min,"COLZ");
  hist1 -> SetTitle("muon_R 1DHist;muon_R;Number of events");
  
  gPad -> Update();
  
  TPaveStats *st1 = (TPaveStats*) hist1 -> FindObject("stats");
  st1 -> SetX1NDC(0.7);
  st1 -> SetX2NDC(0.9);
  st1 -> SetY1NDC(0.8);
  st1 -> SetY2NDC(1.0);

  hist1 -> Draw();




  //charge:charge_SA
  ccpt -> cd (3);

  TH2D *hist2 = new TH2D("hist2","title",10,-2,2,10,-2,2);
  tree -> Draw("charge:charge_SA >> hist2",C_R && C_max_min,"COLZ");
  hist2 -> SetTitle("charge:charge_SA;charge:charge_SA;Number of events");

  gPad -> Update();

  TPaveStats *st2 = (TPaveStats*) hist2 -> FindObject("stats");
  st2 -> SetX1NDC(0.7);
  st2 -> SetX2NDC(0.9);
  st2 -> SetY1NDC(0.8);
  st2 -> SetY2NDC(1.0);

  hist2 -> Draw("COLZ");


  ///nocut
  ccpt -> cd(2);

  TH2D *hist3 = new TH2D("hist3","title",300,-30,30,300,-30,30);
  tree -> Draw("charge*muonPt/1000 :L2SAPt >> hist3",C_R && C_max_min,"COLZ");
  hist3 -> SetTitle("muon ; offline muon pt;L2SA muon pt;Number of events");

  gPad -> Update();

  TPaveStats *st3 = (TPaveStats*) hist3 -> FindObject("stats");
  st3 -> SetX1NDC(0.7);
  st3 -> SetX2NDC(0.9);
  st3 -> SetY1NDC(0.8);
  st3 -> SetY2NDC(1.0);

  hist3 -> Draw("COLZ");


  //charge:charge_SA
  ccpt -> cd (4);

  TH2D *hist4 = new TH2D("hist4","title",100,0,0.1,100,0,25);
  tree -> Draw("muonPt/1000:muon_R >> hist4",C_R && C_max_min,"COLZ");
 
  hist4 -> SetTitle("muon_R:muonPt;muon_R;muonPt;Number of events");

  gPad -> Update();

  TPaveStats *st4 = (TPaveStats*) hist4 -> FindObject("stats");
  st4 -> SetX1NDC(0.7);
  st4 -> SetX2NDC(0.9);
  st4 -> SetY1NDC(0.8);
  st4 -> SetY2NDC(1.0);

  hist4 -> Draw("COLZ");

/*
  ///nocut
  ccpt -> cd(4);

  TH2D *hist4 = new TH2D("hist4","title",300,-30,30,300,-30,30);
  tree -> Draw("charge*muonPt/1000 :L2SAPt >> hist4","muon_R < 0.1 && charge == charge_SA && (quality == 0 || quality == 1)","COLZ");
  hist4 -> SetTitle("muon ; offline muon pt;L2SA muon pt;Number of events");

  gPad -> Update();

  TPaveStats *st4 = (TPaveStats*) hist4 -> FindObject("stats");
  st4 -> SetX1NDC(0.7);
  st4 -> SetX2NDC(0.9);
  st4 -> SetY1NDC(0.8);
  st4 -> SetY2NDC(1.0);

  hist4 -> Draw("COLZ");
*/
  return 0;
}
