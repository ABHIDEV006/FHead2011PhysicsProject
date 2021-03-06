{
   gROOT->LoadMacro("../15663_ClosurePlots/Functions.C");

   TFile F1("StraightAA6Dijet.root");
   TFile F4("StraightPP6Dijet.root");
   TFile F6("ScaledResult1PP6Dijet.root");
   TFile F8("ScaledResult13PP6Dijet.root");
   TFile F8s("ScaledResult13PP6Dijet-small.root");
   TFile F10("ScaledResult17PP6Dijet.root");
   TFile F16("PPDataHightPTJet.root");
   TTree *T1 = (TTree *)F1.Get("Tree");
   TTree *T4 = (TTree *)F4.Get("Tree");
   TTree *T6 = (TTree *)F6.Get("OutputTree");
   TTree *T8 = (TTree *)F8.Get("OutputTree");
   TTree *T8s = (TTree *)F8s.Get("OutputTree");
   TTree *T10 = (TTree *)F10.Get("OutputTree");
   TTree *T16 = (TTree *)F16.Get("OutputTree");

   if(T1)   T1->SetAlias("PTWeightToAAData", "(1/(1.01000-exp(11.4934-0.103388*JetPT)))");
   if(T1)   T1->SetAlias("RawJetDPhi", "(JetPhi-NewJetPhi)");
   if(T1)   T1->SetAlias("JetDPhi", "(RawJetDPhi+2*3.1415926535*(RawJetDPhi<-3.1415926535)-2*3.1415926535*(RawJetDPhi>3.1415926535))");
   if(T1)   T1->SetAlias("JetDEta", "(JetEta-NewJetEta)");
   if(T1)   T1->SetAlias("JetShift", "sqrt(JetDPhi*JetDPhi+JetDEta*JetDEta)");

   if(T1)   T1->SetAlias("C0", "(Centrality < 0.1)");
   if(T1)   T1->SetAlias("C1", "(Centrality < 0.3 && Centrality >= 0.1)");
   if(T1)   T1->SetAlias("C2", "(Centrality < 0.5 && Centrality >= 0.3)");
   if(T1)   T1->SetAlias("C3", "(Centrality < 0.8 && Centrality >= 0.5)");
   if(T1)   T1->SetAlias("C4", "(Centrality < 1.0 && Centrality >= 0.8)");
   
   if(T4)   T4->SetAlias("PTWeightToPPData", "(1/(1.06469-exp(5.61511-0.0524620*JetPT)))");

   if(T1)  T1->SetAlias("IsX", "(RefPartonFlavor == -999)");
   if(T1)  T1->SetAlias("IsD", "(RefPartonFlavor == 1 || RefPartonFlavor == -1)");
   if(T1)  T1->SetAlias("IsU", "(RefPartonFlavor == 2 || RefPartonFlavor == -2)");
   if(T1)  T1->SetAlias("IsS", "(RefPartonFlavor == 3 || RefPartonFlavor == -3)");
   if(T1)  T1->SetAlias("IsC", "(RefPartonFlavor == 4 || RefPartonFlavor == -4)");
   if(T1)  T1->SetAlias("IsB", "(RefPartonFlavor == 5 || RefPartonFlavor == -5)");
   if(T1)  T1->SetAlias("IsG", "(RefPartonFlavor == 21)");
   if(T1)  T1->SetAlias("IsLight", "(IsU || IsD || IsS)");
   if(T1)  T1->SetAlias("IsHeavy", "(IsC || IsB)");
   if(T1)  T1->SetAlias("IsQ", "(IsU || IsD || IsC || IsS || IsB)");
   if(T1)  T1->SetAlias("PartonCategory", "(IsX*0+IsLight*1+IsHeavy*2+IsG*3)");
   if(T4)  T4->SetAlias("IsX", "(RefPartonFlavor == -999)");
   if(T4)  T4->SetAlias("IsD", "(RefPartonFlavor == 1 || RefPartonFlavor == -1)");
   if(T4)  T4->SetAlias("IsU", "(RefPartonFlavor == 2 || RefPartonFlavor == -2)");
   if(T4)  T4->SetAlias("IsS", "(RefPartonFlavor == 3 || RefPartonFlavor == -3)");
   if(T4)  T4->SetAlias("IsC", "(RefPartonFlavor == 4 || RefPartonFlavor == -4)");
   if(T4)  T4->SetAlias("IsB", "(RefPartonFlavor == 5 || RefPartonFlavor == -5)");
   if(T4)  T4->SetAlias("IsG", "(RefPartonFlavor == 21)");
   if(T4)  T4->SetAlias("IsLight", "(IsU || IsD || IsS)");
   if(T4)  T4->SetAlias("IsHeavy", "(IsC || IsB)");
   if(T4)  T4->SetAlias("IsQ", "(IsU || IsD || IsC || IsS || IsB)");
   if(T4)  T4->SetAlias("PartonCategory", "(IsX*0+IsLight*1+IsHeavy*2+IsG*3)");

   if(T6)  T6->SetAlias("ExcessPT", "((TotalPT-0.8*0.8*3.1415926535*Rho)/4)");
   if(T6)  T6->SetAlias("ExcessPT2", "(TotalPTInJet-0.4*0.4*3.1415926535*Rho)");
   if(T6)  T6->SetAlias("AdjustedExcessPT", "(ExcessPT*(ExcessPT>0)+ExcessPT*16*(ExcessPT<0))");
   if(T6)  T6->SetAlias("SmearWeight", "(exp(-ExcessPT*ExcessPT / (2*18*18)) / exp(-ExcessPT*ExcessPT / (2*21.4*21.4)))");
   if(T6)  T6->SetAlias("SmearWeightV2Positive", "(12891000*exp(-0.5*((ExcessPT+0.236714)/27.4658)**2))");
   if(T6)  T6->SetAlias("SmearWeightV2Negative", "(exp(15.5537+0.322953*ExcessPT)+9063180*exp(-0.5*((ExcessPT+2.73170)/14.3526)**2))");
   if(T6)  T6->SetAlias("SmearWeightV2", "(exp(-ExcessPT*ExcessPT/(2*18*18))/(((ExcessPT>0)*SmearWeightV2Positive)+((ExcessPT<0)*SmearWeightV2Negative)))");
   if(T6)  T6->SetAlias("SmearWeightV3", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T6)  T6->SetAlias("SmearWeightV4", "(exp(-ExcessPT*ExcessPT / (2*12.8*12.8)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T6)  T6->SetAlias("SmearWeightV5", "(exp(-ExcessPT*ExcessPT / (2*7.5*7.5)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T6)  T6->SetAlias("SmearWeightV6", "(exp(-ExcessPT*ExcessPT / (2*3.1*3.1)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T6)  T6->SetAlias("RawJetDPhi", "(JetPhi-NewJetPhi)");
   if(T6)  T6->SetAlias("JetDPhi", "(RawJetDPhi+2*3.1415926535*(RawJetDPhi<-3.1415926535)-2*3.1415926535*(RawJetDPhi>3.1415926535))");
   if(T6)  T6->SetAlias("JetDEta", "(JetEta-NewJetEta)");
   if(T6)  T6->SetAlias("JetShift", "sqrt(JetDPhi*JetDPhi+JetDEta*JetDEta)");
   if(T6)  T6->SetAlias("RawBestJetDPhi", "(JetPhi-BestJetPhi)");
   if(T6)  T6->SetAlias("BestJetDPhi", "(RawBestJetDPhi+2*3.1415926535*(RawBestJetDPhi<-3.1415926535)-2*3.1415926535*(RawBestJetDPhi>3.1415926535))");
   if(T6)  T6->SetAlias("BestJetDEta", "(JetEta-BestJetEta)");
   if(T6)  T6->SetAlias("BestJetShift", "sqrt(BestJetDPhi*BestJetDPhi+BestJetDEta*BestJetDEta)");
   if(T6)  T6->SetAlias("PTWeightToEmbedded", "(0.929846+exp(9.16730-0.0754417*NewJetPT))");
   if(T6)  T6->SetAlias("PTWeightToEmbeddedCentral", "(0.725818+0.628636*exp(-(NewJetPT-77.054)*(NewJetPT-77.054)/(2*40.616*40.616)))");
   if(T6)  T6->SetAlias("JetShiftWeight", "(exp(-JetShift*JetShift/(2*0.1*0.1)))");
   if(T6)  T6->SetAlias("SmearWeightInJet", "(exp(-ExcessPT*ExcessPT / (2*15.2*15.2)) / exp(-ExcessPT*ExcessPT / (2*31.13*31.13)))");
   if(T6)  T6->SetAlias("SmearWeightInJet2", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*32.17*32.17)))");
   if(T6)  T6->SetAlias("SmearWeightAdjusted", "(((AdjustedExcessPT>0)+16*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*16*16))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*17.2*17.2))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T6)  T6->SetAlias("JetPTWeight", "(1 / (0.526940+0.475752*erf(0.0379893*(JetPT-95.6267))))");
   if(T6)  T6->SetAlias("SmearWeightAdjusted2", "(((AdjustedExcessPT>0)+16*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*16*16))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*12.8*12.8))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T6)  T6->SetAlias("JetPTWeight2", "(1 / (0.126940+0.875752*erf(0.0379893*(JetPT-95.6267))))");
   if(T6)  T6->SetAlias("ExcessPTExtraWeight", "(exp(-(AdjustedExcessPT*AdjustedExcessPT)/(2*17.2*17.2))/(exp(-(AdjustedExcessPT-11.5)*(AdjustedExcessPT-11.5)/(2*17*17))))");

   if(T6)  T6->SetAlias("rng", "sin(2*pi*rndm)*sqrt(-2*log(rndm))");
   if(T6)  T6->SetAlias("Smear10", "(rng*0.10+1)");
   if(T6)  T6->SetAlias("Smear3", "(rng*0.03+1)");
   if(T6)  T6->SetAlias("Smear1", "(rng*0.01+1)");

   if(T8)  T8->SetAlias("ExcessPT", "((TotalPT-1.2*1.2*3.1415926535*Rho)/9)");
   if(T8)  T8->SetAlias("ExcessPT2", "(TotalPTInJet-0.4*0.4*3.1415926535*Rho)");
   if(T8)  T8->SetAlias("AdjustedExcessPT", "(ExcessPT*(ExcessPT>0)+ExcessPT*9*(ExcessPT<0))");
   if(T8)  T8->SetAlias("SmearWeight", "(exp(-ExcessPT*ExcessPT / (2*18*18)) / exp(-ExcessPT*ExcessPT / (2*21.4*21.4)))");
   if(T8)  T8->SetAlias("SmearWeightV2Positive", "(12891000*exp(-0.5*((ExcessPT+0.236714)/27.4658)**2))");
   if(T8)  T8->SetAlias("SmearWeightV2Negative", "(exp(15.5537+0.322953*ExcessPT)+9063180*exp(-0.5*((ExcessPT+2.73170)/14.3526)**2))");
   if(T8)  T8->SetAlias("SmearWeightV2", "(exp(-ExcessPT*ExcessPT/(2*18*18))/(((ExcessPT>0)*SmearWeightV2Positive)+((ExcessPT<0)*SmearWeightV2Negative)))");
   if(T8)  T8->SetAlias("SmearWeightV3", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T8)  T8->SetAlias("SmearWeightV4", "(exp(-ExcessPT*ExcessPT / (2*12.8*12.8)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T8)  T8->SetAlias("SmearWeightV5", "(exp(-ExcessPT*ExcessPT / (2*7.5*7.5)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T8)  T8->SetAlias("SmearWeightV6", "(exp(-ExcessPT*ExcessPT / (2*3.1*3.1)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T8)  T8->SetAlias("RawJetDPhi", "(JetPhi-NewJetPhi)");
   if(T8)  T8->SetAlias("JetDPhi", "(RawJetDPhi+2*3.1415926535*(RawJetDPhi<-3.1415926535)-2*3.1415926535*(RawJetDPhi>3.1415926535))");
   if(T8)  T8->SetAlias("JetDEta", "(JetEta-NewJetEta)");
   if(T8)  T8->SetAlias("JetShift", "sqrt(JetDPhi*JetDPhi+JetDEta*JetDEta)");
   if(T8)  T8->SetAlias("RawBestJetDPhi", "(JetPhi-BestJetPhi)");
   if(T8)  T8->SetAlias("BestJetDPhi", "(RawBestJetDPhi+2*3.1415926535*(RawBestJetDPhi<-3.1415926535)-2*3.1415926535*(RawBestJetDPhi>3.1415926535))");
   if(T8)  T8->SetAlias("BestJetDEta", "(JetEta-BestJetEta)");
   if(T8)  T8->SetAlias("BestJetShift", "sqrt(BestJetDPhi*BestJetDPhi+BestJetDEta*BestJetDEta)");
   if(T8)  T8->SetAlias("PTWeightToEmbedded", "(0.929846+exp(9.16730-0.0754417*NewJetPT))");
   if(T8)  T8->SetAlias("PTWeightToEmbeddedCentral", "(0.725818+0.628636*exp(-(NewJetPT-77.054)*(NewJetPT-77.054)/(2*40.616*40.616)))");
   if(T8)  T8->SetAlias("JetShiftWeight", "(exp(-JetShift*JetShift/(2*0.1*0.1)))");
   if(T8)  T8->SetAlias("SmearWeightInJet", "(exp(-ExcessPT*ExcessPT / (2*15.2*15.2)) / exp(-ExcessPT*ExcessPT / (2*31.13*31.13)))");
   if(T8)  T8->SetAlias("SmearWeightInJet2", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*32.17*32.17)))");
   if(T8)  T8->SetAlias("SmearWeightAdjusted", "(((AdjustedExcessPT>0)+9*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*9*9))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*17.2*17.2))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T8)  T8->SetAlias("JetPTWeight", "(1 / (0.526940+0.475752*erf(0.0379893*(JetPT-95.6267))))");
   if(T8)  T8->SetAlias("SmearWeightAdjusted2", "(((AdjustedExcessPT>0)+9*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*9*9))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*4.8*4.8))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T8)  T8->SetAlias("JetPTWeight2", "(1 / (0.126940+0.875752*erf(0.0379893*(JetPT-95.6267))))");
   if(T8)  T8->SetAlias("ExcessPTExtraWeight", "(exp(-(AdjustedExcessPT*AdjustedExcessPT)/(2*17.2*17.2))/(exp(-(AdjustedExcessPT-11.5)*(AdjustedExcessPT-11.5)/(2*17*17))))");

   if(T8)  T8->SetAlias("rng", "sin(2*pi*rndm)*sqrt(-2*log(rndm))");
   if(T8)  T8->SetAlias("Smear10", "(rng*0.10+1)");
   if(T8)  T8->SetAlias("Smear3", "(rng*0.03+1)");
   if(T8)  T8->SetAlias("Smear1", "(rng*0.01+1)");

   if(T8s)  T8s->SetAlias("ExcessPT", "((TotalPT-1.2*1.2*3.1415926535*Rho)/9)");
   if(T8s)  T8s->SetAlias("ExcessPT2", "(TotalPTInJet-0.4*0.4*3.1415926535*Rho)");
   if(T8s)  T8s->SetAlias("AdjustedExcessPT", "(ExcessPT*(ExcessPT>0)+ExcessPT*9*(ExcessPT<0))");
   if(T8s)  T8s->SetAlias("SmearWeight", "(exp(-ExcessPT*ExcessPT / (2*18*18)) / exp(-ExcessPT*ExcessPT / (2*21.4*21.4)))");
   if(T8s)  T8s->SetAlias("SmearWeightV2Positive", "(12891000*exp(-0.5*((ExcessPT+0.236714)/27.4658)**2))");
   if(T8s)  T8s->SetAlias("SmearWeightV2Negative", "(exp(15.5537+0.322953*ExcessPT)+9063180*exp(-0.5*((ExcessPT+2.73170)/14.3526)**2))");
   if(T8s)  T8s->SetAlias("SmearWeightV2", "(exp(-ExcessPT*ExcessPT/(2*18*18))/(((ExcessPT>0)*SmearWeightV2Positive)+((ExcessPT<0)*SmearWeightV2Negative)))");
   if(T8s)  T8s->SetAlias("SmearWeightV3", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T8s)  T8s->SetAlias("SmearWeightV4", "(exp(-ExcessPT*ExcessPT / (2*12.8*12.8)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T8s)  T8s->SetAlias("SmearWeightV5", "(exp(-ExcessPT*ExcessPT / (2*7.5*7.5)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T8s)  T8s->SetAlias("SmearWeightV6", "(exp(-ExcessPT*ExcessPT / (2*3.1*3.1)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T8s)  T8s->SetAlias("RawJetDPhi", "(JetPhi-NewJetPhi)");
   if(T8s)  T8s->SetAlias("JetDPhi", "(RawJetDPhi+2*3.1415926535*(RawJetDPhi<-3.1415926535)-2*3.1415926535*(RawJetDPhi>3.1415926535))");
   if(T8s)  T8s->SetAlias("JetDEta", "(JetEta-NewJetEta)");
   if(T8s)  T8s->SetAlias("JetShift", "sqrt(JetDPhi*JetDPhi+JetDEta*JetDEta)");
   if(T8s)  T8s->SetAlias("RawBestJetDPhi", "(JetPhi-BestJetPhi)");
   if(T8s)  T8s->SetAlias("BestJetDPhi", "(RawBestJetDPhi+2*3.1415926535*(RawBestJetDPhi<-3.1415926535)-2*3.1415926535*(RawBestJetDPhi>3.1415926535))");
   if(T8s)  T8s->SetAlias("BestJetDEta", "(JetEta-BestJetEta)");
   if(T8s)  T8s->SetAlias("BestJetShift", "sqrt(BestJetDPhi*BestJetDPhi+BestJetDEta*BestJetDEta)");
   if(T8s)  T8s->SetAlias("PTWeightToEmbedded", "(0.929846+exp(9.16730-0.0754417*NewJetPT))");
   if(T8s)  T8s->SetAlias("PTWeightToEmbeddedCentral", "(0.725818+0.628636*exp(-(NewJetPT-77.054)*(NewJetPT-77.054)/(2*40.616*40.616)))");
   if(T8s)  T8s->SetAlias("JetShiftWeight", "(exp(-JetShift*JetShift/(2*0.1*0.1)))");
   if(T8s)  T8s->SetAlias("SmearWeightInJet", "(exp(-ExcessPT*ExcessPT / (2*15.2*15.2)) / exp(-ExcessPT*ExcessPT / (2*31.13*31.13)))");
   if(T8s)  T8s->SetAlias("SmearWeightInJet2", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*32.17*32.17)))");
   if(T8s)  T8s->SetAlias("SmearWeightAdjusted", "(((AdjustedExcessPT>0)+9*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*9*9))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*17.2*17.2))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T8s)  T8s->SetAlias("JetPTWeight", "(1 / (0.526940+0.475752*erf(0.0379893*(JetPT-95.6267))))");
   if(T8s)  T8s->SetAlias("SmearWeightAdjusted2", "(((AdjustedExcessPT>0)+9*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*9*9))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*4.8*4.8))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T8s)  T8s->SetAlias("JetPTWeight2", "(1 / (0.126940+0.875752*erf(0.0379893*(JetPT-95.6267))))");
   if(T8s)  T8s->SetAlias("ExcessPTExtraWeight", "(exp(-(AdjustedExcessPT*AdjustedExcessPT)/(2*17.2*17.2))/(exp(-(AdjustedExcessPT-11.5)*(AdjustedExcessPT-11.5)/(2*17*17))))");

   if(T8s)  T8s->SetAlias("rng", "sin(2*pi*rndm)*sqrt(-2*log(rndm))");
   if(T8s)  T8s->SetAlias("Smear10", "(rng*0.10+1)");
   if(T8s)  T8s->SetAlias("Smear3", "(rng*0.03+1)");
   if(T8s)  T8s->SetAlias("Smear1", "(rng*0.01+1)");

   if(T10)  T10->SetAlias("ExcessPT", "((TotalPT-1.6*1.6*3.1415926535*Rho)/16)");
   if(T10)  T10->SetAlias("ExcessPT2", "(TotalPTInJet-0.4*0.4*3.1415926535*Rho)");
   if(T10)  T10->SetAlias("AdjustedExcessPT", "(ExcessPT*(ExcessPT>0)+ExcessPT*16*(ExcessPT<0))");
   if(T10)  T10->SetAlias("SmearWeight", "(exp(-ExcessPT*ExcessPT / (2*18*18)) / exp(-ExcessPT*ExcessPT / (2*21.4*21.4)))");
   if(T10)  T10->SetAlias("SmearWeightV2Positive", "(12891000*exp(-0.5*((ExcessPT+0.236714)/27.4658)**2))");
   if(T10)  T10->SetAlias("SmearWeightV2Negative", "(exp(15.5537+0.322953*ExcessPT)+9063180*exp(-0.5*((ExcessPT+2.73170)/14.3526)**2))");
   if(T10)  T10->SetAlias("SmearWeightV2", "(exp(-ExcessPT*ExcessPT/(2*18*18))/(((ExcessPT>0)*SmearWeightV2Positive)+((ExcessPT<0)*SmearWeightV2Negative)))");
   if(T10)  T10->SetAlias("SmearWeightV3", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T10)  T10->SetAlias("SmearWeightV4", "(exp(-ExcessPT*ExcessPT / (2*12.8*12.8)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T10)  T10->SetAlias("SmearWeightV5", "(exp(-ExcessPT*ExcessPT / (2*7.5*7.5)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T10)  T10->SetAlias("SmearWeightV6", "(exp(-ExcessPT*ExcessPT / (2*3.1*3.1)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T10)  T10->SetAlias("RawJetDPhi", "(JetPhi-NewJetPhi)");
   if(T10)  T10->SetAlias("JetDPhi", "(RawJetDPhi+2*3.1415926535*(RawJetDPhi<-3.1415926535)-2*3.1415926535*(RawJetDPhi>3.1415926535))");
   if(T10)  T10->SetAlias("JetDEta", "(JetEta-NewJetEta)");
   if(T10)  T10->SetAlias("JetShift", "sqrt(JetDPhi*JetDPhi+JetDEta*JetDEta)");
   if(T10)  T10->SetAlias("RawBestJetDPhi", "(JetPhi-BestJetPhi)");
   if(T10)  T10->SetAlias("BestJetDPhi", "(RawBestJetDPhi+2*3.1415926535*(RawBestJetDPhi<-3.1415926535)-2*3.1415926535*(RawBestJetDPhi>3.1415926535))");
   if(T10)  T10->SetAlias("BestJetDEta", "(JetEta-BestJetEta)");
   if(T10)  T10->SetAlias("BestJetShift", "sqrt(BestJetDPhi*BestJetDPhi+BestJetDEta*BestJetDEta)");
   if(T10)  T10->SetAlias("PTWeightToEmbedded", "(0.929846+exp(9.16730-0.0754417*NewJetPT))");
   if(T10)  T10->SetAlias("PTWeightToEmbeddedCentral", "(0.725818+0.628636*exp(-(NewJetPT-77.054)*(NewJetPT-77.054)/(2*40.616*40.616)))");
   if(T10)  T10->SetAlias("JetShiftWeight", "(exp(-JetShift*JetShift/(2*0.1*0.1)))");
   if(T10)  T10->SetAlias("SmearWeightInJet", "(exp(-ExcessPT*ExcessPT / (2*15.2*15.2)) / exp(-ExcessPT*ExcessPT / (2*31.13*31.13)))");
   if(T10)  T10->SetAlias("SmearWeightInJet2", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*32.17*32.17)))");
   if(T10)  T10->SetAlias("SmearWeightAdjusted", "(((AdjustedExcessPT>0)+16*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*16*16))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*17.2*17.2))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T10)  T10->SetAlias("JetPTWeight", "(1 / (0.526940+0.475752*erf(0.0379893*(JetPT-95.6267))))");
   if(T10)  T10->SetAlias("SmearWeightAdjusted2", "(((AdjustedExcessPT>0)+16*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*16*16))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*12.8*12.8))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T10)  T10->SetAlias("JetPTWeight2", "(1 / (0.126940+0.875752*erf(0.0379893*(JetPT-95.6267))))");
   if(T10)  T10->SetAlias("ExcessPTExtraWeight", "(exp(-(AdjustedExcessPT*AdjustedExcessPT)/(2*17.2*17.2))/(exp(-(AdjustedExcessPT-11.5)*(AdjustedExcessPT-11.5)/(2*17*17))))");

   if(T10)  T10->SetAlias("rng", "sin(2*pi*rndm)*sqrt(-2*log(rndm))");
   if(T10)  T10->SetAlias("Smear10", "(rng*0.10+1)");
   if(T10)  T10->SetAlias("Smear3", "(rng*0.03+1)");
   if(T10)  T10->SetAlias("Smear1", "(rng*0.01+1)");

   if(T16)  T16->SetAlias("ExcessPT", "((TotalPT-1.2*1.2*3.1415926535*Rho)/9)");
   if(T16)  T16->SetAlias("ExcessPT2", "(TotalPTInJet-0.4*0.4*3.1415926535*Rho)");
   if(T16)  T16->SetAlias("AdjustedExcessPT", "(ExcessPT*(ExcessPT>0)+ExcessPT*9*(ExcessPT<0))");
   if(T16)  T16->SetAlias("SmearWeight", "(exp(-ExcessPT*ExcessPT / (2*18*18)) / exp(-ExcessPT*ExcessPT / (2*21.4*21.4)))");
   if(T16)  T16->SetAlias("SmearWeightV2Positive", "(12891000*exp(-0.5*((ExcessPT+0.236714)/27.4658)**2))");
   if(T16)  T16->SetAlias("SmearWeightV2Negative", "(exp(15.5537+0.322953*ExcessPT)+9063180*exp(-0.5*((ExcessPT+2.73170)/14.3526)**2))");
   if(T16)  T16->SetAlias("SmearWeightV2", "(exp(-ExcessPT*ExcessPT/(2*18*18))/(((ExcessPT>0)*SmearWeightV2Positive)+((ExcessPT<0)*SmearWeightV2Negative)))");
   if(T16)  T16->SetAlias("SmearWeightV3", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T16)  T16->SetAlias("SmearWeightV4", "(exp(-ExcessPT*ExcessPT / (2*12.8*12.8)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T16)  T16->SetAlias("SmearWeightV5", "(exp(-ExcessPT*ExcessPT / (2*7.5*7.5)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T16)  T16->SetAlias("SmearWeightV6", "(exp(-ExcessPT*ExcessPT / (2*3.1*3.1)) / exp(-ExcessPT*ExcessPT / (2*27.4*27.4)))");
   if(T16)  T16->SetAlias("RawJetDPhi", "(JetPhi-NewJetPhi)");
   if(T16)  T16->SetAlias("JetDPhi", "(RawJetDPhi+2*3.1415926535*(RawJetDPhi<-3.1415926535)-2*3.1415926535*(RawJetDPhi>3.1415926535))");
   if(T16)  T16->SetAlias("JetDEta", "(JetEta-NewJetEta)");
   if(T16)  T16->SetAlias("JetShift", "sqrt(JetDPhi*JetDPhi+JetDEta*JetDEta)");
   if(T16)  T16->SetAlias("RawBestJetDPhi", "(JetPhi-BestJetPhi)");
   if(T16)  T16->SetAlias("BestJetDPhi", "(RawBestJetDPhi+2*3.1415926535*(RawBestJetDPhi<-3.1415926535)-2*3.1415926535*(RawBestJetDPhi>3.1415926535))");
   if(T16)  T16->SetAlias("BestJetDEta", "(JetEta-BestJetEta)");
   if(T16)  T16->SetAlias("BestJetShift", "sqrt(BestJetDPhi*BestJetDPhi+BestJetDEta*BestJetDEta)");
   if(T16)  T16->SetAlias("PTWeightToEmbedded", "(0.929846+exp(9.16730-0.0754417*NewJetPT))");
   if(T16)  T16->SetAlias("PTWeightToEmbeddedCentral", "(0.725818+0.628636*exp(-(NewJetPT-77.054)*(NewJetPT-77.054)/(2*40.616*40.616)))");
   if(T16)  T16->SetAlias("JetShiftWeight", "(exp(-JetShift*JetShift/(2*0.1*0.1)))");
   if(T16)  T16->SetAlias("SmearWeightInJet", "(exp(-ExcessPT*ExcessPT / (2*15.2*15.2)) / exp(-ExcessPT*ExcessPT / (2*31.13*31.13)))");
   if(T16)  T16->SetAlias("SmearWeightInJet2", "(exp(-ExcessPT*ExcessPT / (2*17.2*17.2)) / exp(-ExcessPT*ExcessPT / (2*32.17*32.17)))");
   if(T16)  T16->SetAlias("SmearWeightAdjusted", "(((AdjustedExcessPT>0)+9*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*9*9))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*17.2*17.2))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T16)  T16->SetAlias("JetPTWeight", "(1 / (0.526940+0.475752*erf(0.0379893*(JetPT-95.6267))))");
   if(T16)  T16->SetAlias("SmearWeightAdjusted2", "(((AdjustedExcessPT>0)+9*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*9*9))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*12.8*12.8))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T16)  T16->SetAlias("SmearWeightAdjusted3", "(((AdjustedExcessPT>0)+9*(AdjustedExcessPT<0)*(exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35))/exp(-AdjustedExcessPT*AdjustedExcessPT/2/(27.35*27.35*9*9))))*(exp(-AdjustedExcessPT*AdjustedExcessPT/(2*7.2*7.2))/exp(-AdjustedExcessPT*AdjustedExcessPT/(2*27.35*27.35))))");
   if(T16)  T16->SetAlias("JetPTWeight2", "(1 / (0.126940+0.875752*erf(0.0379893*(JetPT-95.6267))))");
   if(T16)  T16->SetAlias("ExcessPTExtraWeight", "(exp(-(AdjustedExcessPT*AdjustedExcessPT)/(2*17.2*17.2))/(exp(-(AdjustedExcessPT-11.5)*(AdjustedExcessPT-11.5)/(2*17*17))))");

   if(T16)  T16->SetAlias("rng", "sin(2*pi*rndm)*sqrt(-2*log(rndm))");
   if(T16)  T16->SetAlias("Smear10", "(rng*0.10+1)");
   if(T16)  T16->SetAlias("Smear3", "(rng*0.03+1)");
   if(T16)  T16->SetAlias("Smear1", "(rng*0.01+1)");
}
