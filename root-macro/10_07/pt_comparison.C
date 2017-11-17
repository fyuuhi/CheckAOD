
int pt_comparison()
{


  TCanvas *ccpt = new TCanvas("ccpt","ccpt");
  ccpt -> Divide(2,2);


  ///barrel
  ccpt -> cd(1);

  TH1D *hist1 = new TH1D("hist1","title",100,0,50);
  tree -> Draw("muonPt/1000 >> hist1","muon_R < 0.1");
  hist1 -> SetTitle("offline muon pt;offline muon pt;Number of events");
  
  gPad -> Update();
  
  TPaveStats *st1 = (TPaveStats*) hist1 -> FindObject("stats");
  st1 -> SetX1NDC(0.7);
  st1 -> SetX2NDC(0.9);
  st1 -> SetY1NDC(0.8);
  st1 -> SetY2NDC(1.0);

  hist1 -> Draw();




  ///endcap
  ccpt -> cd (3);

  TH1D *hist2 = new TH1D("hist2","title",100,0,50);
  tree -> Draw("abs(L2SAPt) >> hist2","muon_R < 0.1");
  hist2 -> SetTitle("L2SA muon pt;L2SA muon pt;Number of events");

  gPad -> Update();

  TPaveStats *st2 = (TPaveStats*) hist2 -> FindObject("stats");
  st2 -> SetX1NDC(0.7);
  st2 -> SetX2NDC(0.9);
  st2 -> SetY1NDC(0.8);
  st2 -> SetY2NDC(1.0);

  hist2 -> Draw();


  ///nocut
  ccpt -> cd(2);

  TH2D *hist3 = new TH2D("hist3","title",300,-30,30,300,-30,30);
  tree -> Draw("charge*muonPt/1000 :L2SAPt >> hist3","muon_R < 0.1","COLZ");
  hist3 -> SetTitle("muon ; offline muon pt;L2SA muon pt;Number of events");

  gPad -> Update();

  TPaveStats *st3 = (TPaveStats*) hist3 -> FindObject("stats");
  st3 -> SetX1NDC(0.7);
  st3 -> SetX2NDC(0.9);
  st3 -> SetY1NDC(0.8);
  st3 -> SetY2NDC(1.0);

  hist3 -> Draw("COLZ");

  ///residual
  ccpt -> cd(4);

  TH1D *hist4 = new TH1D("hist4","title",100,-2,1);
  tree -> Draw("muon_residual >> hist4","muon_R < 0.1");
  hist4 -> SetTitle("muon residual;L2SA muon residual;Number of events");

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
