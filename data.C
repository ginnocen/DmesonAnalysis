void data(){


  TString inputdata="nt_DfinderData_HIMinBiasUPC_HIRun2011-14Mar2014-v2_20150912_alpha0p15_lxyz2p5_eta1p1_pt1_ptfiltered.root";
  TFile *inf = new TFile(inputdata.Data());
  TTree *ntDkPpiM = (TTree*)inf->Get("ntDkPpiM");
    
  TH1D *hPtTrack = new TH1D("hPtTrack","",1000,-10,10);
  ntDkPpiM->Project("hPtTrack","Dtrk2Eta","1");
  hPtTrack->Draw();
  
}
