//Jian file: (1/2*fprompt*Yields)/(Nmb*BR*efficiency*TAA)  
//Nmb=3.01781340000000000e+07
//TAA=5.67*1e-9
//BR=0.0388
//fprompt=0.9

//D0_pbpb_spectrum modified=(1/2*fprompt*Yields)/(Nmb*BR*efficiency) 
//my spectrum modified =1/2*prompt/(BR*Nmb) *Yields/Eff

//Our file  Yields/efficiency

void compareNew(){

  TFile *fileJian=new TFile("InputsPurdueNoWeights/PromptRAA_D0_PbPb_spectrum_fonll_effunpre_cent0to100_ptbin12_y1_dataplusfonll_noweight.root");
  TH1D *hspectrumJian = (TH1D*)fileJian->Get("D0_pbpb_spectrum");

  hspectrumJian->Scale(5.67*1e-9);
  
  TFile *fileMIT=new TFile("InputsMIT/alphaD0.root");
  TH1D *hspectrumMIT = (TH1D*)fileMIT->Get("hPtCor");
  TH1D *hrawMIT = (TH1D*)fileMIT->Get("hPt");
  hspectrumMIT->Scale(1./(2*0.0388*28042407.));
  
  TCanvas*c=new TCanvas("c","",500,500);
  c->cd();
  c->SetLogy();
  hspectrumMIT->Draw();
  hspectrumMIT->SetLineWidth(4);
  hspectrumJian->Draw("same");
    
  for (int i=1;i<11;i++){
  cout<<"pt centre="<<hspectrumMIT->GetBinCenter(i)<<",value="<<hspectrumMIT->GetBinContent(i)/hspectrumJian->GetBinContent(i+3)<<endl;
  }
}