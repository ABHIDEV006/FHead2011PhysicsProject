#include <iostream>
#include <vector>

#include "TTree.h"
#include "TFile.h"

#define JETCOUNTMAX 200
#define GENCOUNTMAX 100

class HiEventTreeMessenger;
class RhoTreeMessenger;
class SkimTreeMessenger;
class JetTreeMessenger;
class GenParticleTreeMessenger;
class PFTreeMessenger;
class TriggerTreeMessenger;
class HLTBitTreeMessenger;

class HiEventTreeMessenger
{
public:
   TTree *Tree;
   float hiHF;
   int hiBin;
   unsigned int Run;
   unsigned long long Event;
   unsigned int Lumi;
public:
   HiEventTreeMessenger(TFile &File);
   HiEventTreeMessenger(TTree *HiEventTree);
   bool Initialize(TTree *HiEventTree);
   bool Initialize();
   bool GetEntry(int iEntry);
};

class RhoTreeMessenger
{
public:
   TTree *Tree;
   std::vector<double> *EtaMax;
   std::vector<double> *Rho;
   std::vector<double> *RhoM;
public:
   RhoTreeMessenger(TFile &File);
   RhoTreeMessenger(TTree *RhoTree);
   bool Initialize(TTree *RhoTree);
   bool Initialize();
   bool GetEntry(int iEntry);
};

class SkimTreeMessenger
{
public:
   TTree *Tree;
   int HBHENoise;
   int HBHENoiseRun2Loose;
   int PVFilter;
   int ClusterCompatibilityFilter;
   int HFCoincidenceFilter;
   int CollisionEventSelection;
public:
   SkimTreeMessenger(TFile &File);
   SkimTreeMessenger(TTree *SkimTree);
   bool Initialize(TTree *SkimTree);
   bool Initialize();
   bool GetEntry(int iEntry);
   bool PassBasicFilter();
};

class JetTreeMessenger
{
public:
   TTree *Tree;
   float PTHat;
   int JetCount;
   float JetRawPT[JETCOUNTMAX];
   float JetPT[JETCOUNTMAX];
   float JetEta[JETCOUNTMAX];
   float JetY[JETCOUNTMAX];
   float JetPhi[JETCOUNTMAX];
   float JetPU[JETCOUNTMAX];
   float JetM[JETCOUNTMAX];
   float JetArea[JETCOUNTMAX];
   std::vector<std::vector<float> > *JetSubJetPT;
   std::vector<std::vector<float> > *JetSubJetEta;
   std::vector<std::vector<float> > *JetSubJetPhi;
   std::vector<std::vector<float> > *JetSubJetM;
   float JetSym[JETCOUNTMAX];
   int JetDroppedBranches[JETCOUNTMAX];
   float RefPT[JETCOUNTMAX];
   float RefEta[JETCOUNTMAX];
   float RefY[JETCOUNTMAX];
   float RefPhi[JETCOUNTMAX];
   float RefM[JETCOUNTMAX];
   float RefArea[JETCOUNTMAX];
   float RefGPT[JETCOUNTMAX];
   float RefGEta[JETCOUNTMAX];
   float RefGPhi[JETCOUNTMAX];
   float RefGM[JETCOUNTMAX];
   float RefPartonPT[JETCOUNTMAX];
   int RefPartonFlavor[JETCOUNTMAX];
   int RefPartonFlavorForB[JETCOUNTMAX];
   std::vector<std::vector<float> > *RefGSubJetPT;
   std::vector<std::vector<float> > *RefGSubJetEta;
   std::vector<std::vector<float> > *RefGSubJetPhi;
   std::vector<std::vector<float> > *RefGSubJetM;
   int GenCount;
   int GenMatchIndex[JETCOUNTMAX];
   float GenPT[JETCOUNTMAX];
   float GenEta[JETCOUNTMAX];
   float GenY[JETCOUNTMAX];
   float GenPhi[JETCOUNTMAX];
   float GenM[JETCOUNTMAX];
public:
   JetTreeMessenger(TFile &File, std::string TreeName = "akCs4PFJetAnalyzer/t");
   JetTreeMessenger(TTree *JetTree);
   bool Initialize(TTree *JetTree);
   bool Initialize();
   bool GetEntry(int iEntry);
};

class GenParticleTreeMessenger
{
public:
   TTree *Tree;
   float NPart;
   float NColl;
   float NHard;
   float Phi0;
   std::vector<float> *PT;
   std::vector<float> *Eta;
   std::vector<float> *Phi;
   std::vector<int> *ID;
   std::vector<int> *Charge;
   std::vector<int> *DaughterCount;
public:
   GenParticleTreeMessenger(TFile &File);
   GenParticleTreeMessenger(TTree *GenParticleTree);
   bool Initialize(TTree *GenParticleTree);
   bool Initialize();
   bool GetEntry(int iEntry);
};

class PFTreeMessenger
{
public:
   TTree *Tree;
   std::vector<int> *ID;
   std::vector<float> *PT;
   std::vector<float> *E;
   std::vector<float> *Eta;
   std::vector<float> *Phi;
public:
   PFTreeMessenger(TFile &File, std::string TreeName = "pfcandAnalyzer/pfTree");
   PFTreeMessenger(TTree *PFTree);
   bool Initialize(TTree *PFTree);
   bool Initialize();
   bool GetEntry(int iEntry);
};

class TriggerTreeMessenger
{
public:
   TTree *Tree;
   int Run;
   unsigned long long Event;
   int Lumi;
   std::vector<std::string> Name;
   std::vector<int> Decision;
   std::vector<bool> Exist;
public:
   TriggerTreeMessenger(TFile &File, std::string TreeName = "hltanalysis/HltTree");
   TriggerTreeMessenger(TTree *TriggerTree);
   bool Initialize(TTree *TriggerTree);
   bool Initialize();
   bool GetEntry(int iEntry);
   void FillTriggerNames();
   int FindIndex(std::string Trigger);
   int CheckTrigger(std::string Trigger);
   int CheckTrigger(int Index);
};




