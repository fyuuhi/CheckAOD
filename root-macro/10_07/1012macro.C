{
//TFile *tf = new TFile("run/output/JPsi_019.AOD.root");
 TFile *file = TFile::Open("run/output/JPsi_019.AOD.root");
 TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));


std::vector<Double_t> *charge;
std::vector<Double_t> *charge_SA;
std::vector<Double_t> *muonPt;
std::vector<Double_t> *L2SAPt;
std::vector<Double_t> *muon_R;

tree->SetBranchAddress("charge",&charge);
tree->SetBranchAddress("charge_SA",&charge_SA);
tree->SetBranchAddress("muonPt",&muonPt);
tree->SetBranchAddress("L2SAPt",&L2SAPt);
tree->SetBranchAddress("muon_R",&muon_R);
//tree->SetBranchAddress("charge",charge);
//tree->SetBranchAddress("charge",charge);

Int_t nEntries = (Int_t) tree->GetEntries();

for(Int_t i=0;i<10;++i)
{
    tree->GetEntry(i);
/*    
    for(Int_t j=0;j < muonPt@.size();++j)
    {
        if( muonPt.at(j) < mu1 )
        {
            mu1 = 

        }
    }

*/
    tree->Draw("muonPt");

}



}
