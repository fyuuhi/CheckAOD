
int residual_distri_barrel_endcap()
{

  
  TCanvas *cadd4 = new TCanvas("cadd4","cadd4");
  cadd4 -> Divide(3,3);

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

  TH1D *hist = new TH1D("hist","title",100,-3.5,3.5);
  tree -> Draw("muon_residual >> hist",dR && qua_t_m);
  hist -> SetTitle("muonPt residual;muon residual;Entries");

  gPad -> Update();

  TPaveStats *st = (TPaveStats*) hist -> FindObject("stats");
  st -> SetX1NDC(0.7);
  st -> SetX2NDC(0.9);
  st -> SetY1NDC(0.8);
  st -> SetY2NDC(1.0);

  hist -> Draw();



  cadd4 -> cd(2);

  TH1D *hist_b = new TH1D("hist_b","title",100,-3.5,3.5);
  tree -> Draw("muon_residual >> hist_b",dR && qua_t_m && barrel);
  hist_b -> SetTitle("muonPt residual (barrel);muon residual;Entries");

  gPad -> Update();

  TPaveStats *stb = (TPaveStats*) hist_b -> FindObject("stats");
  stb -> SetX1NDC(0.7);
  stb -> SetX2NDC(0.9);
  stb -> SetY1NDC(0.8);
  stb -> SetY2NDC(1.0);

  hist_b -> Draw();


  cadd4 -> cd(3);

  TH1D *hist_e = new TH1D("hist_e","title",100,-3.5,3.5);
  tree -> Draw("muon_residual >> hist_e",dR && qua_t_m && endcap);
  hist_e -> SetTitle("muonPt residual (endcap);muon residual;Entries");

  gPad -> Update();

  TPaveStats *ste = (TPaveStats*) hist_e -> FindObject("stats");
  ste -> SetX1NDC(0.7);
  ste -> SetX2NDC(0.9);
  ste -> SetY1NDC(0.8);
  ste -> SetY2NDC(1.0);


  hist_e -> Draw();

 
  cadd4 -> cd(4);

  TH2D *hist_2 = new TH2D("hist_2","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:phiMS >> hist_2",dR && qua_t_m);
  hist_2 -> SetTitle("muonPt residual:phiMS;phi;muonPt residual");

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




  cadd4 -> cd(5);

  TH2D *hist_2b = new TH2D("hist_2b","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:phiMS >> hist_2b",dR && qua_t_m && barrel);
  hist_2b -> SetTitle("muonPt residual:phiMS(barrel);phi;muonPt residual");

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


  cadd4 -> cd(6);

  TH2D *hist_2e = new TH2D("hist_2e","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:phiMS >> hist_2e",dR && qua_t_m && endcap);
  hist_2e -> SetTitle("muonPt residual:phiMS(endcap);phi;muonPt residual");

  hist_2e -> SetStats(0);

  hist_2e -> GetXaxis() -> SetTitleSize(0.05);
  hist_2e -> GetYaxis() -> SetTitleSize(0.05);
  hist_2e -> GetYaxis() -> SetTitleOffset(1.05);

  hist_2e -> GetXaxis() -> SetLabelSize(0.05);
  hist_2e -> GetYaxis() -> SetLabelSize(0.05);



/*
  gPad -> Update();

  TPaveStats *st2e = (TPaveStats*) hist_2e -> FindObject("stats");
  st2e -> SetX1NDC(0.7);
  st2e -> SetX2NDC(0.9);
  st2e -> SetY1NDC(0.8);
  st2e -> SetY2NDC(1.0);
*/
  hist_2e -> Draw("COLZ");

  cadd4 -> cd(7);

  TH2D *hist_phi2 = new TH2D("hist_phi2","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:etaMS >> hist_phi2",dR && qua_t_m);
  hist_phi2 -> SetTitle("muonPt residual:etaMS;eta;muonPt residual");

  hist_phi2 -> SetStats(0);

  hist_phi2 -> GetXaxis() -> SetTitleSize(0.05);
  hist_phi2 -> GetYaxis() -> SetTitleSize(0.05);
  hist_phi2 -> GetYaxis() -> SetTitleOffset(1.05);

  hist_phi2 -> GetXaxis() -> SetLabelSize(0.05);
  hist_phi2 -> GetYaxis() -> SetLabelSize(0.05);



/*
  gPad -> Update();

  TPaveStats *st2e = (TPaveStats*) hist_2e -> FindObject("stats");
  st2e -> SetX1NDC(0.7);
  st2e -> SetX2NDC(0.9);
  st2e -> SetY1NDC(0.8);
  st2e -> SetY2NDC(1.0);
*/
  hist_phi2 -> Draw("COLZ");




  cadd4 -> cd(8);

  TH2D *hist_phi2plus = new TH2D("hist_phi2plus","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:etaMS >> hist_phi2plus",dR && qua_t_m && phi_plus );
  hist_phi2plus -> SetTitle("muonPt residual:etaMS(phi>0);eta;muonPt residual");

  hist_phi2plus -> SetStats(0);

  hist_phi2plus -> GetXaxis() -> SetTitleSize(0.05);
  hist_phi2plus -> GetYaxis() -> SetTitleSize(0.05);
  hist_phi2plus -> GetYaxis() -> SetTitleOffset(1.05);

  hist_phi2plus -> GetXaxis() -> SetLabelSize(0.05);
  hist_phi2plus -> GetYaxis() -> SetLabelSize(0.05);



/*
  gPad -> Update();

  TPaveStats *st2e = (TPaveStats*) hist_2e -> FindObject("stats");
  st2e -> SetX1NDC(0.7);
  st2e -> SetX2NDC(0.9);
  st2e -> SetY1NDC(0.8);
  st2e -> SetY2NDC(1.0);
*/
  hist_phi2plus -> Draw("COLZ");



  cadd4 -> cd(9);

  TH2D *hist_phi2minus = new TH2D("hist_phi2minus","title",200,-3.5,3.5,200,-2,1);
  tree -> Draw("muon_residual:etaMS >> hist_phi2minus",dR && qua_t_m && phi_minus);
  hist_phi2minus -> SetTitle("muonPt residual:etaMS(phi<0);eta;muonPt residual");

  hist_phi2minus -> SetStats(0);

  hist_phi2minus -> GetXaxis() -> SetTitleSize(0.05);
  hist_phi2minus -> GetYaxis() -> SetTitleSize(0.05);
  hist_phi2minus -> GetYaxis() -> SetTitleOffset(1.05);

  hist_phi2minus -> GetXaxis() -> SetLabelSize(0.05);
  hist_phi2minus -> GetYaxis() -> SetLabelSize(0.05);



/*
  gPad -> Update();

  TPaveStats *st2e = (TPaveStats*) hist_2e -> FindObject("stats");
  st2e -> SetX1NDC(0.7);
  st2e -> SetX2NDC(0.9);
  st2e -> SetY1NDC(0.8);
  st2e -> SetY2NDC(1.0);
*/
  hist_phi2minus -> Draw("COLZ");







return 0;


}
