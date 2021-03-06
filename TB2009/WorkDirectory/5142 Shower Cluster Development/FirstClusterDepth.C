{
   gROOT->SetStyle("Plain");

//=========Macro generated from canvas: c1/c1
//=========  (Tue Aug 18 18:19:48 2009) by ROOT version5.18/00a
   TCanvas *c1 = new TCanvas("c1", "c1",8,49,699,499);
   c1->Range(-2.474468,-236.9333,17.50851,2096.86);
   c1->SetBorderSize(2);
   c1->SetFrameFillColor(0);
   
   TH1 *FirstClusterDepth = new TH1D("FirstClusterDepth","Depth of first cluster",64,-0.5,15.5);
   FirstClusterDepth->SetBinContent(2,7);
   FirstClusterDepth->SetBinContent(3,56);
   FirstClusterDepth->SetBinContent(4,26);
   FirstClusterDepth->SetBinContent(5,60);
   FirstClusterDepth->SetBinContent(6,804);
   FirstClusterDepth->SetBinContent(7,503);
   FirstClusterDepth->SetBinContent(8,1123);
   FirstClusterDepth->SetBinContent(9,1598);
   FirstClusterDepth->SetBinContent(10,1777);
   FirstClusterDepth->SetBinContent(11,1345);
   FirstClusterDepth->SetBinContent(12,1192);
   FirstClusterDepth->SetBinContent(13,1162);
   FirstClusterDepth->SetBinContent(14,1194);
   FirstClusterDepth->SetBinContent(15,984);
   FirstClusterDepth->SetBinContent(16,951);
   FirstClusterDepth->SetBinContent(17,922);
   FirstClusterDepth->SetBinContent(18,945);
   FirstClusterDepth->SetBinContent(19,788);
   FirstClusterDepth->SetBinContent(20,710);
   FirstClusterDepth->SetBinContent(21,670);
   FirstClusterDepth->SetBinContent(22,693);
   FirstClusterDepth->SetBinContent(23,558);
   FirstClusterDepth->SetBinContent(24,494);
   FirstClusterDepth->SetBinContent(25,480);
   FirstClusterDepth->SetBinContent(26,491);
   FirstClusterDepth->SetBinContent(27,372);
   FirstClusterDepth->SetBinContent(28,356);
   FirstClusterDepth->SetBinContent(29,320);
   FirstClusterDepth->SetBinContent(30,397);
   FirstClusterDepth->SetBinContent(31,315);
   FirstClusterDepth->SetBinContent(32,256);
   FirstClusterDepth->SetBinContent(33,276);
   FirstClusterDepth->SetBinContent(34,272);
   FirstClusterDepth->SetBinContent(35,210);
   FirstClusterDepth->SetBinContent(36,231);
   FirstClusterDepth->SetBinContent(37,187);
   FirstClusterDepth->SetBinContent(38,202);
   FirstClusterDepth->SetBinContent(39,175);
   FirstClusterDepth->SetBinContent(40,150);
   FirstClusterDepth->SetBinContent(41,148);
   FirstClusterDepth->SetBinContent(42,145);
   FirstClusterDepth->SetBinContent(43,147);
   FirstClusterDepth->SetBinContent(44,130);
   FirstClusterDepth->SetBinContent(45,124);
   FirstClusterDepth->SetBinContent(46,131);
   FirstClusterDepth->SetBinContent(47,99);
   FirstClusterDepth->SetBinContent(48,94);
   FirstClusterDepth->SetBinContent(49,44);
   FirstClusterDepth->SetBinContent(50,43);
   FirstClusterDepth->SetBinContent(51,33);
   FirstClusterDepth->SetBinContent(52,32);
   FirstClusterDepth->SetBinContent(53,33);
   FirstClusterDepth->SetBinContent(54,62);
   FirstClusterDepth->SetBinContent(55,68);
   FirstClusterDepth->SetBinContent(56,105);
   FirstClusterDepth->SetBinContent(57,81);
   FirstClusterDepth->SetBinContent(58,76);
   FirstClusterDepth->SetBinContent(59,68);
   FirstClusterDepth->SetBinContent(60,37);
   FirstClusterDepth->SetBinContent(61,40);
   FirstClusterDepth->SetBinContent(62,59);
   FirstClusterDepth->SetBinContent(63,6);
   FirstClusterDepth->SetBinContent(65,2271);
   FirstClusterDepth->SetEntries(27328);
   FirstClusterDepth->SetStats(0);
   
   TF1 *exp = new TF1("exp","expo",2.5,10);
   exp->SetFillColor(19);
   exp->SetFillStyle(0);
   exp->SetLineWidth(3);
   exp->SetChisquare(77.34648);
   exp->SetParameter(0,7.903312);
   exp->SetParError(0,0.02262228);
   exp->SetParLimits(0,0,0);
   exp->SetParameter(1,-0.3035833);
   exp->SetParError(1,0.004271441);
   exp->SetParLimits(1,0,0);
   FirstClusterDepth->GetListOfFunctions()->Add(exp);
   FirstClusterDepth->Draw("");
   
   TPaveText *pt = new TPaveText(0.01,0.9401777,0.3315332,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(2);
   pt->SetFillColor(0);
   text = pt->AddText("Depth of first cluster");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
