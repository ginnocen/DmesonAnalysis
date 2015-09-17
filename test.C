void test(){

  TString selmcgen = "Gpt>28.&&Gpt<40&&(GisSignal==1||GisSignal==2)";

  TString inputmc="ntD_20150914_DinderMC_Pyquen_D0tokaonpion_D0pt1p0_PthatAll_TuneZ2_Unquenched_2760GeV_20150912_EvtBase_alpha0p15.root";
  TFile *infMC = new TFile(inputmc.Data());

  TTree *ntMC = (TTree*)infMC->Get("ntDkPpiM");
  TTree *ntGen = (TTree*)infMC->Get("ntGen");
 // ntGen->AddFriend(ntMC);
  
  
  TH1D *hPtMC = new TH1D("hPtMC","",100,0,100);
  TH1D *hPtMCGen = new TH1D("hPtMCGen","",100,0,100);
  ntMC->Project("hPtMC","Dpt","Dpt>28&&Dpt<40&&Dgen==23333");
  ntGen->Project("hPtMCGen","Gpt",selmcgen.Data());
  cout<<"number of entries GEN"<<hPtMCGen->GetEntries()<<endl;
  cout<<"number of entries matched"<<hPtMC->GetEntries()<<endl;
  hPtMC->Draw();
  
}
