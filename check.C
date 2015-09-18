#include "utilities.h"
#include "fitD.h"

double luminosity=150.;
double setparam0=100.;
double setparam1=1.865;
double setparam2=0.03;
double setparam10=0.005;
double setparam8=0.1;
double setparam9=0.1;
double fixparam1=1.865;

TString inputdata="nt_DfinderData_HIMinBiasUPC_HIRun2011-14Mar2014-v2_20150912_alpha0p15_lxyz2p5_eta1p1_pt1_ptfiltered.root";
TString inputmc="ntD_20150914_DinderMC_Pyquen_D0tokaonpion_D0pt1p0_PthatAll_TuneZ2_Unquenched_2760GeV_20150912_EvtBase_alpha0p15.root";


int binsIndex=1;
TString cut = cuts[binsIndex];
TString seldata = Form("%s",cut.Data());
TString selmc = seldata;
TString selmcgen = "GisSignal==1||GisSignal==2";

void check(){

  TString infname=inputdata.Data();
  TFile *inf = new TFile(infname.Data());
  TFile *infMC = new TFile(inputmc.Data());

  TTree *nt = (TTree*) inf->Get("ntDkMpiP");
  TTree *nt2 = (TTree*) inf->Get("ntDkPpiM");
  
  TH1D*hnew=new TH1D("hnew","hnew",100,0,100);
  
  //nt->Project("hnew","Dpt","1");
  //hnew->Draw();
  
  
  const int maxDperevent=100000;
  int EvtNo,EvtNo2;
  int Dsize,Dsize2;
  Double_t Dpt[maxDperevent];
  Double_t Dpt2[maxDperevent];
  Double_t Dmass[maxDperevent];
  Double_t Dmass2[maxDperevent];

  Double_t Dtrk1MassHypo[maxDperevent];
  Double_t Dtrk2MassHypo[maxDperevent];
  
  Double_t Dtrk1Pt[maxDperevent];
  Double_t Dtrk2Pt[maxDperevent];
  Double_t Dtrk1Pt2[maxDperevent];
  Double_t Dtrk2Pt2[maxDperevent];
  
  Double_t Dtrk1MassHypo2[maxDperevent];
  Double_t Dtrk2MassHypo2[maxDperevent];



  nt->SetBranchAddress("EvtNo",&EvtNo);
  nt->SetBranchAddress("Dsize",&Dsize);
  nt->SetBranchAddress("Dpt",Dpt);
  nt->SetBranchAddress("Dmass",Dmass);
  nt->SetBranchAddress("Dtrk1Pt",Dtrk1Pt);
  nt->SetBranchAddress("Dtrk2Pt",Dtrk2Pt);
  nt->SetBranchAddress("Dtrk1MassHypo",Dtrk1MassHypo);
  nt->SetBranchAddress("Dtrk2MassHypo",Dtrk2MassHypo);

  nt2->SetBranchAddress("EvtNo",&EvtNo2);
  nt2->SetBranchAddress("Dsize",&Dsize2);
  nt2->SetBranchAddress("Dpt",Dpt2);
  nt2->SetBranchAddress("Dmass",Dmass2);
  nt2->SetBranchAddress("Dtrk1Pt",Dtrk1Pt2);
  nt2->SetBranchAddress("Dtrk2Pt",Dtrk2Pt2);
  nt2->SetBranchAddress("Dtrk1MassHypo",Dtrk1MassHypo2);
  nt2->SetBranchAddress("Dtrk2MassHypo",Dtrk2MassHypo2);



  
  
  for (int entry=0;entry<nt->GetEntries();entry++){ 
    nt->GetEntry(entry);
    if(EvtNo==30362945){
      for (int i=0;i<Dsize;i++){ 
        cout<<"Kpi Dmeson pt"<<Dpt[i]<<endl;
        cout<<"Kpi Dmeson mass"<<Dmass[i]<<endl;
        cout<<"Kpi track 1 mass"<<Dtrk1Pt[i]<<endl;
        cout<<"Kpi track 2 mass"<<Dtrk2Pt[i]<<endl;
        cout<<"Kpi hyp 1 "<<Dtrk1MassHypo[i]<<endl;
        cout<<"Kpi hyp 2 "<<Dtrk2MassHypo[i]<<endl;
      }
    }
  }  
  
  for (int entry=0;entry<nt2->GetEntries();entry++){ 
    nt2->GetEntry(entry);
    if(EvtNo2==30362945){
      for (int i=0;i<Dsize2;i++){ 
        cout<<"piK Dmeson pt"<<Dpt2[i]<<endl;
        cout<<"piK Dmeson mass"<<Dmass2[i]<<endl;
        cout<<"piK track 1 mass"<<Dtrk1Pt2[i]<<endl;
        cout<<"piK track 2 mass"<<Dtrk2Pt2[i]<<endl;
        cout<<"piK hyp 1 "<<Dtrk1MassHypo2[i]<<endl;
        cout<<"piK hyp 2 "<<Dtrk2MassHypo2[i]<<endl;


      }
    }
  // cout<<"new event"<<endl;    
  }  

}
