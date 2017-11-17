

int highpt_comparison()
{

 // TPad *cvs = new TPad("cvs","cvs");
  TCanvas *c1 = new TCanvas("c1","c1");
  c1 -> Divide(1,2);

  TCanvas *c2 =new TCanvas("c2","c2");

  ///highPtPos

  c1-> cd(1);


  TH1D *hist1 = new TH1D("hist1","title",100,0,50);
  tree -> Draw("highPtPos/1000 >> hist1");
  hist1 -> SetTitle("highPtPos;highPtPos;Number of events");
  
  gPad -> Update();
  
  TPaveStats *st1 = (TPaveStats*) hist1 -> FindObject("stats");
  st1 -> SetX1NDC(0.7);
  st1 -> SetX2NDC(0.9);
  st1 -> SetY1NDC(0.8);
  st1 -> SetY2NDC(1.0);

  hist1 -> Draw();


  ///highPtNeg
  c1 -> cd (2);

  TH1D *hist2 = new TH1D("hist2","title",100,0,50);
  tree -> Draw("highPtNeg/1000 >> hist2");
  hist2 -> SetTitle("highPtNeg;L2SA muon pt;Number of events");

  gPad -> Update();

  TPaveStats *st2 = (TPaveStats*) hist2 -> FindObject("stats");
  st2 -> SetX1NDC(0.7);
  st2 -> SetX2NDC(0.9);
  st2 -> SetY1NDC(0.8);
  st2 -> SetY2NDC(1.0);

  hist2 -> Draw();


  ///highPtPos vs highPtNeg
  c2 -> cd();

  TH2D *hist3 = new TH2D("hist3","title",300,0,30,300,0,30);
  tree -> Draw("highPtPos/1000 :highPtNeg/1000 >> hist3","","COLZ");
  hist3 -> SetTitle("muon ; offline muon pt;L2SA muon pt;Number of events");

  gPad -> Update();

  TPaveStats *st3 = (TPaveStats*) hist3 -> FindObject("stats");
  st3 -> SetX1NDC(0.7);
  st3 -> SetX2NDC(0.9);
  st3 -> SetY1NDC(0.8);
  st3 -> SetY2NDC(1.0);

  hist3 -> Draw("COLZ");



  return 0;
}
