
int residual_distri_normalize()
{

  
  TCanvas *cadd3 = new TCanvas("cadd3","cadd3");
//  cadd -> Divide(3,2);

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
//  cadd -> cd (1);

  TH1D *hist_L1 = new TH1D("hist_L1","title",400,-2,1);
  TH1D *hist_LS1 = new TH1D("hist_LS1","title",400,-2,1);
  TH1D *hist_S1 = new TH1D("hist_S1","title",400,-2,1);
  TH1D *hist_SS1 = new TH1D("hist_SS1","title",400,-2,1);
  tree -> Draw("muon_residual >> hist_L1",dR && qua_t_m && barrel && Large);
  tree -> Draw("muon_residual >> hist_LS1",dR && qua_t_m && barrel && Large_Special);
  tree -> Draw("muon_residual >> hist_S1",dR && qua_t_m && barrel && Small);
  tree -> Draw("muon_residual >> hist_SS1",dR && qua_t_m && barrel && Small_Special);

  hist_L1 -> SetLineColor(6);
  hist_LS1 -> SetLineColor(2);
  hist_S1 -> SetLineColor(4);
  hist_SS1 -> SetLineColor(1);


  hist_L1 -> SetStats(0);
  hist_LS1 -> SetStats(0);
  hist_S1 -> SetStats(0);
  hist_SS1 -> SetStats(0);

/*
hist_L1 ->Draw();
hist_LS1 ->Draw("SAME");
hist_S1 ->Draw("SAME");
hist_SS1 ->Draw("SAME");
*/


  hist_L1 -> DrawNormalized("",1./(hist_L1->GetBinWidth(1))); 
  hist_LS1 -> DrawNormalized("SAME",1./(hist_LS1->GetBinWidth(1))); 
  hist_S1 -> DrawNormalized("SAME",1./(hist_S1->GetBinWidth(1))); 
  hist_SS1 -> DrawNormalized("SAME",1./(hist_SS1->GetBinWidth(1))); 



  TLegend *leg = new TLegend(0.1,0.7,0.48,0.9);

  leg->AddEntry(hist_L1,"Large","f");
  leg->AddEntry(hist_LS1,"Large Special","f");
  leg->AddEntry(hist_S1,"Small","f");
  leg->AddEntry(hist_SS1,"Small Special","f");
  
  leg -> Draw();


/*
  hist_L ->Draw();
  hist_LS ->Draw("SAME");
  hist_S ->Draw("SAME");
  hist_SS ->Draw("SAME");
*/

return 0;


}
