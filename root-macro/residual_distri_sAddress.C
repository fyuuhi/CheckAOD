int residual_distri_sAddress()
{

  
  TCanvas *cadd = new TCanvas("cadd","cadd");
  cadd -> Divide(3,2);

  TCut barrel = "abs(muon_eta) < 1.05";
  TCut endcap = "abs(muon_eta) > 1.05";

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



///Large
  cadd -> cd (1);

  TH1D *hist_L = new TH1D("hist_L","title",100,-1,1);
  tree -> Draw("muon_residual >> hist_L",dR && qua_t_m && barrel && Large);
  hist_L -> SetTitle("Large;muon residual;Entries");

  gPad -> Update();

  TPaveStats *stL = (TPaveStats*) hist_L -> FindObject("stats");
  stL -> SetX1NDC(0.8);
  stL -> SetX2NDC(1.0);
  stL -> SetY1NDC(0.8);
  stL -> SetY2NDC(1.0);


  hist_L -> GetXaxis() -> SetTitleSize(0.05);
  hist_L -> GetYaxis() -> SetTitleSize(0.03);
  hist_L -> GetYaxis() -> SetTitleOffset(1.9);

  hist_L -> GetXaxis() -> SetLabelSize(0.04);
  hist_L -> GetYaxis() -> SetLabelSize(0.03);




  hist_L -> Draw();


///Large_Special
  cadd -> cd (2);

  TH1D *hist_LS = new TH1D("hist_LS","title",100,-1,1);
  tree -> Draw("muon_residual >> hist_LS",dR && qua_t_m && barrel && Large_Special);
  hist_LS -> SetTitle("Large_Specail;muon residual;Entries");

  gPad -> Update();

  TPaveStats *stLS = (TPaveStats*) hist_LS -> FindObject("stats");
  stLS -> SetX1NDC(0.8);
  stLS -> SetX2NDC(1.0);
  stLS -> SetY1NDC(0.8);
  stLS -> SetY2NDC(1.0);

  hist_LS -> GetXaxis() -> SetTitleSize(0.05);
  hist_LS -> GetYaxis() -> SetTitleSize(0.03);
  hist_LS -> GetYaxis() -> SetTitleOffset(1.9);

  hist_LS -> GetXaxis() -> SetLabelSize(0.04);
  hist_LS -> GetYaxis() -> SetLabelSize(0.03);



  hist_LS -> Draw();


///Small
  cadd -> cd (4);

  TH1D *hist_S = new TH1D("hist_S","title",100,-1,1);
  tree -> Draw("muon_residual >> hist_S",dR && qua_t_m && barrel && Small);
  hist_S -> SetTitle("Small;muon residual;Entries");

  gPad -> Update();

  TPaveStats *stS = (TPaveStats*) hist_S -> FindObject("stats");
  stS -> SetX1NDC(0.8);
  stS -> SetX2NDC(1.0);
  stS -> SetY1NDC(0.8);
  stS -> SetY2NDC(1.0);

  hist_S -> GetXaxis() -> SetTitleSize(0.05);
  hist_S -> GetYaxis() -> SetTitleSize(0.03);
  hist_S -> GetYaxis() -> SetTitleOffset(1.9);

  hist_S -> GetXaxis() -> SetLabelSize(0.04);
  hist_S -> GetYaxis() -> SetLabelSize(0.03);



  hist_S -> Draw();


///Small_Special
  cadd -> cd (5);

  TH1D *hist_SS = new TH1D("hist_SS","title",100,-1,1);
  tree -> Draw("muon_residual >> hist_SS",dR && qua_t_m && barrel && Small_Special);
  hist_SS -> SetTitle("Small_special;muon residual;Entries");

  gPad -> Update();

  TPaveStats *stSS = (TPaveStats*) hist_SS -> FindObject("stats");
  stSS -> SetX1NDC(0.8);
  stSS -> SetX2NDC(1.0);
  stSS -> SetY1NDC(0.8);
  stSS -> SetY2NDC(1.0);

  hist_SS -> GetXaxis() -> SetTitleSize(0.05);
  hist_SS -> GetYaxis() -> SetTitleSize(0.03);
  hist_SS -> GetYaxis() -> SetTitleOffset(1.9);

  hist_SS -> GetXaxis() -> SetLabelSize(0.04);
  hist_SS -> GetYaxis() -> SetLabelSize(0.03);



  hist_SS -> Draw();


/*
  TCanvas *cadd2 = new TCanvas("cadd2","cadd2");
*/

/*
  Double_t tot_L = hist_L -> Integral();
  Double_t tot_LS = hist_LS -> Integral();
  Double_t tot_S = hist_S -> Integral();
  Double_t tot_SS = hist_SS -> Integral();

  hist_L -> Scale(1./tot_L);
  hist_LS -> Scale(1./tot_LS);
  hist_S -> Scale(1./tot_S);
  hist_SS -> Scale(1./tot_SS);
*/

/*
  Double_t ot_L = hist_L -> Integral()/hist_L -> Integral();
  Double_t ot_LS = hist_L -> Integral()/hist_LS -> Integral();
  Double_t ot_S = hist_L -> Integral()/hist_S -> Integral();
  Double_t ot_SS = hist_L -> Integral()/hist_SS -> Integral();

  hist_L -> Scale(ot_L);
  hist_LS -> Scale(ot_LS);
  hist_S -> Scale(ot_S);
  hist_SS -> Scale(ot_SS);


  hist_L -> Draw();
  hist_LS -> Draw("SAME");
  hist_S -> Draw("SAME");
  hist_SS -> Draw("SAME");
*/


/*
  hist_L -> DrawNormalized("",1./(hist_L->GetBinWidth(1))); 
  hist_LS -> DrawNormalized("SAME",1./(hist_LS->GetBinWidth(1))); 
  hist_S -> DrawNormalized("SAME",1./(hist_S->GetBinWidth(1))); 
  hist_SS -> DrawNormalized("SAME",1./(hist_SS->GetBinWidth(1))); 
 

  hist_L -> SetLineColor(2);
  hist_LS -> SetLineColor(3);
  hist_S -> SetLineColor(4);
  hist_SS -> SetLineColor(5);
*/

  cadd -> cd (6);
  
  TH2D *hist_MS = new TH2D("hist_MS","title",200,-3.5,3.5,4,0,4);
  tree -> Draw("sAddress:phiMS >> hist_MS",dR && qua_t_m && barrel);
  hist_MS -> SetTitle("phiMS:sAddress;phiMS;sAddress");

  gPad -> Update();

  TPaveStats *stMS = (TPaveStats*) hist_MS -> FindObject("stats");
  stMS -> SetX1NDC(0.7);
  stMS -> SetX2NDC(0.9);
  stMS -> SetY1NDC(0.8);
  stMS -> SetY2NDC(1.0);

  hist_MS -> Draw("COLZ");








  return 0;
}
