
int residual_10171()
{

  const Int_t NRGBs = 5;
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, 256);


  
  TCanvas *cadd4 = new TCanvas("cadd4","cadd4");
  cadd4 -> Divide(2,2);

  TCut barrel = "abs(etaMS) < 1.05";
  TCut endcap = "abs(etaMS) > 1.05";
  TCut phi_plus = "phiMS > 0.0";
  TCut phi_minus = "phiMS < 0.0";


  TCut dR = "muon_R < 0.1";

  TCut Large = "sAddress == 0";
  TCut Large_Special = "sAddress == 1";
  TCut Small = "sAddress == 2";
  TCut Small_Special = "sAddress == 3";

  TCut tight = "quality == 0";
  TCut medium = "quality == 1";
  TCut loose = "quality == 2";
  TCut veryloose = "quality == 3";

  TCut qua_t_m = "(quality == 0 || quality == 1)";

 
  cadd4 -> cd(1);

  TH2D *hist_2 = new TH2D("hist_2","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:phiMS >> hist_2",dR && barrel && qua_t_m && Large);
  hist_2 -> SetTitle("Large;phi;muonPt residual");

  hist_2 -> SetStats(0);

  hist_2 -> GetXaxis() -> SetTitleSize(0.05);
  hist_2 -> GetYaxis() -> SetTitleSize(0.05);
  hist_2 -> GetYaxis() -> SetTitleOffset(1.05);

  hist_2 -> GetXaxis() -> SetLabelSize(0.05);
  hist_2 -> GetYaxis() -> SetLabelSize(0.05);



/*
  gPad -> Update();

  TPaveStats *st2 = (TPaveStats*) hist_2 -> FindObject("stats");
  st2 -> SetX1NDC(0.7);
  st2 -> SetX2NDC(0.9);
  st2 -> SetY1NDC(0.8);
  st2 -> SetY2NDC(1.0);

*/
  hist_2 -> Draw("COLZ");




  cadd4 -> cd(2);

  TH2D *hist_2b = new TH2D("hist_2b","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:phiMS >> hist_2b",dR && qua_t_m && barrel && Large_Special);
  hist_2b -> SetTitle("Large Special;phi;muonPt residual");

  hist_2b -> SetStats(0);
  hist_2b -> GetXaxis() -> SetTitleSize(0.05);
  hist_2b -> GetYaxis() -> SetTitleSize(0.05);
  hist_2b -> GetYaxis() -> SetTitleOffset(1.05);

  hist_2b -> GetXaxis() -> SetLabelSize(0.05);
  hist_2b -> GetYaxis() -> SetLabelSize(0.05);


/*  
  gPad -> Update();


  TPaveStats *st2b = (TPaveStats*) hist_2b -> FindObject("stats");
  st2b -> SetX1NDC(0.7);
  st2b -> SetX2NDC(0.9);
  st2b -> SetY1NDC(0.8);
  st2b -> SetY2NDC(1.0);
*/
  hist_2b -> Draw("COLZ");


  cadd4 -> cd(3);

  TH2D *hist_2e = new TH2D("hist_2e","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:phiMS >> hist_2e",dR && qua_t_m && barrel && Small);
  hist_2e -> SetTitle("Small;phi;muonPt residual");

  hist_2e -> SetStats(0);

  hist_2e -> GetXaxis() -> SetTitleSize(0.05);
  hist_2e -> GetYaxis() -> SetTitleSize(0.05);
  hist_2e -> GetYaxis() -> SetTitleOffset(1.05);

  hist_2e -> GetXaxis() -> SetLabelSize(0.05);
  hist_2e -> GetYaxis() -> SetLabelSize(0.05);

  hist_2e -> Draw("COLZ");
  
  cadd4 -> cd(4);

  TH2D *hist_2ei = new TH2D("hist_2ei","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:phiMS >> hist_2ei",dR && qua_t_m && barrel && Small_Special);
  hist_2ei -> SetTitle("Small Special;phi;muonPt residual");

  hist_2ei -> SetStats(0);

  hist_2ei -> GetXaxis() -> SetTitleSize(0.05);
  hist_2ei -> GetYaxis() -> SetTitleSize(0.05);
  hist_2ei -> GetYaxis() -> SetTitleOffset(1.05);

  hist_2ei -> GetXaxis() -> SetLabelSize(0.05);
  hist_2ei -> GetYaxis() -> SetLabelSize(0.05);




/*
  gPad -> Update();

  TPaveStats *st2e = (TPaveStats*) hist_2e -> FindObject("stats");
  st2e -> SetX1NDC(0.7);
  st2e -> SetX2NDC(0.9);
  st2e -> SetY1NDC(0.8);
  st2e -> SetY2NDC(1.0);
*/
  hist_2ei -> Draw("COLZ");





return 0;


}
