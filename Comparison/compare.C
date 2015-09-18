//Jian file: Ds
//Nmb=3.01781340000000000e+07
//TAA=5.67*1e-9
//BR=0.0388
//fprompt=0.9

//D0_pbpb_spectrum modified=(1/2*fprompt*Yields)/(Nmb*BR*efficiency) 
//my spectrum modified =1/2*prompt/(BR*Nmb) *Yields/Eff

//Our file  Yields/efficiency

void compare(){

  TFile *fileJian=new TFile("InputsPurdue/PromptRAA_D0_PbPb_spectrum_fonll_effunpre_cent0to100_ptbin12_y1_dataplusfonll.root");
  TFile *fileRawJian=new TFile("InputsPurdue/Dspectrum_pbpb_data_ptbin_14_ptd_unpreMBtrig_0_cent0to100_y1.root");
  TH1D *hspectrumJian = (TH1D*)fileJian->Get("D0_pbpb_spectrum");
  TH1D *rawJian = (TH1D*)fileRawJian->Get("N_mb_expobkg_count");

  hspectrumJian->Scale(5.67*1e-9);
  
  TFile *fileMIT=new TFile("InputsMIT/alphaD0.root");
  TH1D *hspectrumMIT = (TH1D*)fileMIT->Get("hPtCor");
  TH1D *hrawMIT = (TH1D*)fileMIT->Get("hPt");
  hspectrumMIT->Scale(0.90*1./(2*0.0388*3.01781340000000000e+07));
  
  TCanvas*c=new TCanvas("c","",500,500);
  c->cd();
  c->SetLogy();
  hspectrumMIT->Draw();
  hspectrumMIT->SetLineWidth(4);
  hspectrumJian->Draw("same");
  
  
  
  
  TFile*fEffJian=new TFile("InputsPurdue/D0_PbPb_acc_eff_ptbin_14_ybin_6_prompt_FONLLweight_cent-0to100_dataptshape_y1_Ncollweight1.root");
  TH1D *EffJian = (TH1D*)fEffJian->Get("d0accxeff_pt");
  TH1D *EffMIT = (TH1D*)fileMIT->Get("hEff");
  
  cout<<"bin center MIT"<<EffMIT->GetBinCenter(1)<<"GeV, efficiency="<<EffMIT->GetBinContent(1)<<endl; 
  cout<<"bin center Jian"<<EffJian->GetBinCenter(4)<<"GeV, efficiency="<<EffJian->GetBinContent(4)<<endl; 
  cout<<"bin center MIT"<<hrawMIT->GetBinCenter(1)<<"GeV, raws="<<hrawMIT->GetBinContent(1)<<endl; 
  cout<<"bin center Jian"<<rawJian->GetBinCenter(4)<<"GeV, raws="<<rawJian->GetBinContent(4)<<endl; 
  cout<<"*************"<<endl;
  cout<<"bin center MIT"<<EffMIT->GetBinCenter(7)<<"GeV, efficiency="<<EffMIT->GetBinContent(7)<<endl; 
  cout<<"bin center Jian"<<EffJian->GetBinCenter(10)<<"GeV, efficiency="<<EffJian->GetBinContent(10)<<endl; 
  cout<<"bin center MIT"<<hrawMIT->GetBinCenter(7)<<"GeV, raws="<<hrawMIT->GetBinContent(7)<<endl; 
  cout<<"bin center Jian"<<rawJian->GetBinCenter(10)<<"GeV, raws="<<rawJian->GetBinContent(10)<<endl; 
  
  
  for (int i=1;i<11;i++){
  cout<<"pt centre="<<EffJian->GetBinCenter(i+3)<<",value="<<hspectrumMIT->GetBinContent(i)/hspectrumJian->GetBinContent(i+3)<<endl;
  
  
  
  
  }

  
  

}