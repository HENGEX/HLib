#include <Plotter.h>
#include <TROOT.h>
#include <TSystem.h>
#include "TStyle.h"
#include <sstream>

#define HError(msg) std::cout << "\033[0;31m HLibError: \033[0m" << msg << std::endl;

using namespace Harry;

static UInt_t counter = 0;

static TStyle *tdrStyle = new TStyle("tdrStyle", "Style for P-TDR");

void tdrGrid(bool gridOn)
{
   tdrStyle->SetPadGridX(gridOn);
   tdrStyle->SetPadGridY(gridOn);
}

// fixOverlay: Redraws the axis

void fixOverlay()
{
   gPad->RedrawAxis();
}

void setTDRStyle()
{

   // For the canvas:
   tdrStyle->SetCanvasBorderMode(0);
   tdrStyle->SetCanvasColor(kWhite);
   tdrStyle->SetCanvasDefH(600); // Height of canvas
   tdrStyle->SetCanvasDefW(600); // Width of canvas
   tdrStyle->SetCanvasDefX(0);   // POsition on screen
   tdrStyle->SetCanvasDefY(0);

   // For the Pad:
   tdrStyle->SetPadBorderMode(0);
   // tdrStyle->SetPadBorderSize(Width_t size = 1);
   tdrStyle->SetPadColor(kWhite);
   tdrStyle->SetPadGridX(false);
   tdrStyle->SetPadGridY(false);
   tdrStyle->SetGridColor(0);
   tdrStyle->SetGridStyle(3);
   tdrStyle->SetGridWidth(1);

   // For the frame:
   tdrStyle->SetFrameBorderMode(0);
   tdrStyle->SetFrameBorderSize(1);
   tdrStyle->SetFrameFillColor(0);
   tdrStyle->SetFrameFillStyle(0);
   tdrStyle->SetFrameLineColor(1);
   tdrStyle->SetFrameLineStyle(1);
   tdrStyle->SetFrameLineWidth(1);

   // For the histo:
   // tdrStyle->SetHistFillColor(1);
   // tdrStyle->SetHistFillStyle(0);
   tdrStyle->SetHistLineColor(1);
   tdrStyle->SetHistLineStyle(0);
   tdrStyle->SetHistLineWidth(1);
   // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
   // tdrStyle->SetNumberContours(Int_t number = 20);

   tdrStyle->SetEndErrorSize(2);
   // tdrStyle->SetErrorMarker(20);  // Seems to give an error
   tdrStyle->SetErrorX(0.);

   tdrStyle->SetMarkerStyle(20);

   // For the fit/function:
   tdrStyle->SetOptFit(1);
   tdrStyle->SetFitFormat("5.4g");
   tdrStyle->SetFuncColor(2);
   tdrStyle->SetFuncStyle(1);
   tdrStyle->SetFuncWidth(1);

   // For the date:
   tdrStyle->SetOptDate(0);
   // tdrStyle->SetDateX(Float_t x = 0.01);
   // tdrStyle->SetDateY(Float_t y = 0.01);

   // For the statistics box:
   tdrStyle->SetOptFile(0);
   tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
   tdrStyle->SetStatColor(kWhite);
   tdrStyle->SetStatFont(42);
   tdrStyle->SetStatFontSize(0.025);
   tdrStyle->SetStatTextColor(1);
   tdrStyle->SetStatFormat("6.4g");
   tdrStyle->SetStatBorderSize(1);
   tdrStyle->SetStatH(0.1);
   tdrStyle->SetStatW(0.15);
   // tdrStyle->SetStatStyle(Style_t style = 1001);
   // tdrStyle->SetStatX(Float_t x = 0);
   // tdrStyle->SetStatY(Float_t y = 0);

   // Margins:
   tdrStyle->SetPadTopMargin(0.05);
   tdrStyle->SetPadBottomMargin(0.13);
   tdrStyle->SetPadLeftMargin(0.16);
   tdrStyle->SetPadRightMargin(0.02);

   // For the Global title:
   tdrStyle->SetOptTitle(1); // 0=No Title
   tdrStyle->SetTitleFont(42);
   tdrStyle->SetTitleColor(1);
   tdrStyle->SetTitleTextColor(1);
   tdrStyle->SetTitleFillColor(10);
   tdrStyle->SetTitleFontSize(0.05);
   // tdrStyle->SetTitleH(0); // Set the height of the title box
   // tdrStyle->SetTitleW(0); // Set the width of the title box
   // tdrStyle->SetTitleX(0); // Set the position of the title box
   // tdrStyle->SetTitleY(0.985); // Set the position of the title box
   // tdrStyle->SetTitleStyle(Style_t style = 1001);
   // tdrStyle->SetTitleBorderSize(2);

   // For the axis titles:
   tdrStyle->SetTitleColor(1, "XYZ");
   tdrStyle->SetTitleFont(42, "XYZ");
   tdrStyle->SetTitleSize(0.06, "XYZ");
   // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
   // tdrStyle->SetTitleYSize(Float_t size = 0.02);
   tdrStyle->SetTitleXOffset(0.9);
   tdrStyle->SetTitleYOffset(1.25);
   // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

   // For the axis labels:
   tdrStyle->SetLabelColor(1, "XYZ");
   tdrStyle->SetLabelFont(42, "XYZ");
   tdrStyle->SetLabelOffset(0.007, "XYZ");
   tdrStyle->SetLabelSize(0.05, "XYZ");

   // For the axis:
   tdrStyle->SetAxisColor(1, "XYZ");
   tdrStyle->SetStripDecimals(kTRUE);
   tdrStyle->SetTickLength(0.03, "XYZ");
   tdrStyle->SetNdivisions(510, "XYZ");
   tdrStyle->SetPadTickX(0); // 0=Text labels (and tics) only on bottom, 1=Text labels on top and bottom
   tdrStyle->SetPadTickY(1);

   // Change for log plots:
   tdrStyle->SetOptLogx(0);
   tdrStyle->SetOptLogy(0);
   tdrStyle->SetOptLogz(0);

   // Postscript options:
   tdrStyle->SetPaperSize(20., 20.);
   // tdrStyle->SetLineScalePS(Float_t scale = 3);
   // tdrStyle->SetLineStyleString(Int_t i, const char* text);
   // tdrStyle->SetHeaderPS(const char* header);
   // tdrStyle->SetTitlePS(const char* pstitle);

   // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
   // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
   // tdrStyle->SetPaintTextFormat(const char* format = "g");
   // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
   // tdrStyle->SetTimeOffset(Double_t toffset);
   // tdrStyle->SetHistMinimumZero(kTRUE);

   // gROOT->ForceStyle();  // Try this if stuff doesn't work right

   tdrStyle->cd();
}

//______________________________________________________________________________
Plotter::Plotter(std::string treename, std::vector<std::string> branches, UInt_t bins, Double_t xmin, Double_t xmax)
   : fBranches(branches), fNBins(bins), fXmin(xmin), fXmax(xmax), fOutput(nullptr), fTreeName(treename),fStacksHists(), fSumw2(kFALSE),
     fVerbose(kFALSE)
{
   
}

//______________________________________________________________________________
Plotter::Plotter(const Plotter &p)
{
   fChains = p.fChains;
   fHStacks = p.fHStacks;
   fBranches = p.fBranches;
   fNBins = p.fNBins;
   fXmin = p.fXmin;
   fXmax = p.fXmax;
   fOutput = p.fOutput;
   fCanvas = p.fCanvas;
   fVerbose = p.fVerbose;
}

//______________________________________________________________________________
void Plotter::SetTDRStyle()
{
    setTDRStyle();
}

//______________________________________________________________________________
Plotter::~Plotter()
{
   // TODO: free vectors of pointers and map
   //   if (fCanvas != nullptr)
   //      delete fCanvas;
}

Int_t entries=0;
//______________________________________________________________________________
void Plotter::AddDirectory(const char *path, const char *alias, Double_t weight)
{
   auto verbose = fVerbose;
   SetVerbose(kFALSE);        // I dont want to print paths found here (too much output)
   auto files = Find(path);   // getting paths for files *.root
   SetVerbose(verbose);       // restoring previous status

   if (fVerbose) {
      std::cout << "\n---------------- HLib  AddDirectory ----------------" << std::endl;
      std::cout << " Path = " << path << std::endl;
      std::cout << " Weight = " << weight << std::endl;
   }

   for (auto &file : files) // filling the chain with the files
   {
      if (!AddFile(alias, file.c_str(), weight, TTree::kMaxEntries))
         continue; // if the file is not added continue with the next(error handler in AddFile method)
   }
//    if (fVerbose) {
//       std::cout << "\n Total events in chains " << std::endl;
//       for (auto &chain : fChains) {
//          std::cout << "\n Chain  = " << chain.first << std::endl;
//          std::cout << " Events = " << chain.second->GetEntries() << std::endl;
//       }
//       std::cout<<"Entries sum = "<<entries<<std::endl;
//    }
}
//______________________________________________________________________________
Int_t Plotter::AddFile(const char *alias, const char *filename, Double_t weight, Long64_t nentries)
{
   if (fVerbose) {
      std::cout << "\n---------------- HLib  AddFile ----------------" << std::endl;
      std::cout << " File = " << filename << std::endl;
      std::cout << " Tree = " << fTreeName.c_str() << std::endl;
      std::cout << " Weight = " << weight << std::endl;
      auto cfile = TFile::Open(filename, "READ"); // current file
      if (cfile == NULL) {
         HError("can not open chain file " << filename);
         return kFALSE;
      }

      auto ctree = (TTree *)cfile->Get(fTreeName.c_str());
      if (fVerbose) {
         std::cout << " Entries = " << ctree->GetEntries() << std::endl;
         entries+=ctree->GetEntries();
      }
      cfile->Close();
   }
   std::vector<FileInfo> info;
   if(fFileInfo.count( alias ))
      info = fFileInfo[alias];
   else
       fFileInfo[alias] = info;
    
   FileInfo file;
   file.fFilePath = filename;
   file.fWeight = weight;
   file.fNentries = nentries;
   
   info.push_back(file);
   
   fFileInfo[alias] = info;
   
   return kTRUE;
}

//______________________________________________________________________________
std::map<std::string, std::pair<std::vector<TH1F *>, TLegend *>> &Plotter::GetHists()
{
    if(fStacksHists.empty()){
            for (auto &branch : fBranches) {
                auto hists=GetHists(branch.c_str());
                std::vector<TH1F*> v;
                for(auto &hist:fHists)
                {
                    v.push_back(hist.second[branch.c_str()]);
                }
                fStacksHists[branch]=std::pair<std::vector<TH1F *>, TLegend *>(v,fLegends[branch]);
           }
        return fStacksHists;
    }else{
        return fStacksHists;
    }
}

//______________________________________________________________________________
// std::pair<std::vector<TH1F *>, TLegend *> &Plotter::GetHists(const Char_t *branch)
std::map<std::string,std::map<std::string,TH1F*>>& Plotter::GetHists(const Char_t *branch)
{
   auto color = 2;
//    std::vector<TH1F *> hists;
   for (auto &files : fFileInfo) {
      auto cname = files.first.c_str();

      TCut cuts = "";
      if (fCuts.count(cname))
         cuts = fCuts[cname];
      TString lbranch = branch;
      lbranch = lbranch.ReplaceAll(")", "").ReplaceAll("(", "");
      
      TH1F *hist=nullptr;
      
      
      
      if(fHists.count(cname)) // if the alias exists (Signal, Bgk0 ..)
      {
        auto hmap = fHists[cname];
        if(hmap.count(branch)) //getting histogram if exists
        {
            hist=hmap[branch]; 
        }else//creating an histogram if dont exists
        {
            auto name=Form("%s%s", cname, branch);
            hist=new TH1F(name,name, fNBins, fXmin, fXmax);
            hmap[branch]=hist;
            hist->SetFillColor(color);
            hist->SetLineColor(color);
            // error as sqrt(sum of weights)
            if (fSumw2)
                hist->Sumw2(); // to compute the error on the weights
            fHists[cname]=hmap;
            color++;

        }
      }else{ //creating entries if alias dont exists
           auto name=Form("%s%s", cname, branch);
           hist=new TH1F(name,name, fNBins, fXmin, fXmax);
           std::map<std::string,TH1F*> hmap;
           hmap[branch]=hist;
           hist->SetFillColor(color);
           hist->SetLineColor(color);
           // error as sqrt(sum of weights)
           if (fSumw2)
               hist->Sumw2(); // to compute the error on the weights
         
            fHists[cname]=hmap;
            color++;
      }
      
      //filling the histogram given an alias, branch, weight,tree name and  root file.
      //all files was added previously with the method AddFile of AddDirectory
      for(auto &file:fFileInfo[cname]) 
      {
            auto tfile=TFile::Open(file.fFilePath.c_str(),"READ");
            auto tree=(TTree*)tfile->Get(fTreeName.c_str());
            auto w=Form("%f",file.fWeight);
            TString lbranch = branch;
            lbranch = lbranch.ReplaceAll(")", "").ReplaceAll("(", "");
            
            tree->Draw(Form("%s>>%s(%d,%f,%f)", branch, Form("tmp%s%s", cname, lbranch.Data()), fNBins, fXmin, fXmax),w && cuts && fCut , "goff");
            auto h = (TH1F *)gROOT->FindObject(Form("tmp%s%s", cname, lbranch.Data()));
            gStyle->SetOptStat(1);
            hist->Add(h);
            delete h;
            tfile->Close();
      }
   }
   
    TLegend *leg = nullptr;
    //creating legends
    if(!fLegends.count(branch)) // if the branch exists 
    {
        leg = new TLegend(0.68, 0.72, 0.98, 0.92);
        //filling the Legend
        for (auto &hist : fHists) {
            auto cname = hist.first.c_str();
            auto h=hist.second[branch];
            leg->AddEntry(h, cname, "l");
        }
        fLegends[branch]=leg;
    }
   

//    fStacksHists[branch] = std::pair<std::vector<TH1F *>, TLegend *>(hists, leg);
//    return fStacksHists[branch];
return fHists;
}

//______________________________________________________________________________
std::pair<THStack *, TLegend *> &Plotter::GetHStack(const Char_t *branch)
{

   if (!fHStacks.count(branch)) // creating hstack if dont exists
   {
      GetHists(branch);
      
      std::string aliasnames = "( ";
      std::vector<std::string> aliases;
      for (auto &hist: fHists) {
         auto name = hist.first;
         aliases.push_back(name);
         aliasnames += name;
         aliasnames += " ";
      }
      aliasnames += ")";

      auto hstack = new THStack(Form("PlotterStack%s", branch),
                                Form("Plotter Stack Branch=%s Aliases=%s", branch, aliasnames.c_str()));
      for (auto &hist: fHists) {
          hstack->Add(hist.second[branch]); 
      }      
      fHStacks[branch] = std::pair<THStack *, TLegend *>(hstack, fLegends[branch]);
      return fHStacks[branch];
   } else { // if exists just return the object;
      return fHStacks[branch];
   }
}

//______________________________________________________________________________
std::map<std::string, std::pair<THStack *, TLegend *>> &Plotter::GetPlots()
{
   for (auto &branch : fBranches)
      GetHStack(branch.c_str());
   return fHStacks;
}

//______________________________________________________________________________
void Plotter::SetCut(const Char_t *alias, TCut cut)
{
   fCuts[alias] = cut;
}

//______________________________________________________________________________
void Plotter::SetCut(TCut cut)
{
   fCut = cut;
}

//______________________________________________________________________________
void Plotter::SavePdfs(const Char_t *dir)
{
   if (gSystem->AccessPathName(dir))
      gSystem->mkdir(dir);

   for (auto &branch : fBranches) {
      fCanvas = new TCanvas(Form("c%d", counter));
      counter++;
      auto hstack = GetHStack(branch.c_str());
      auto hs = (THStack *)hstack.first->Clone();
      auto legen = (TLegend *)hstack.second->Clone();
      hs->Draw();
      legen->Draw();
      fCanvas->Draw();
      auto filename = Form("%s/%s.pdf", dir, TString(branch.c_str()).ReplaceAll("(", "").ReplaceAll(")", "").Data());
      fCanvas->SaveAs(filename);
      delete fCanvas;
   }
   fCanvas = nullptr;
}

//______________________________________________________________________________
void Plotter::SavePdf(const Char_t *filename, const Char_t *branch)
{
   fCanvas = new TCanvas(Form("c%d", counter));
   counter++;
   auto hstack = GetHStack(branch);
   hstack.first->Draw();
   hstack.second->Draw();
   fCanvas->Draw();
   fCanvas->SaveAs(filename);
   delete fCanvas;
}

//______________________________________________________________________________
void Plotter::SaveFile(const Char_t *rootfile, const Char_t *mode)
{
   fOutput = new TFile(rootfile, mode);
   auto hists = GetHists();
   auto plots = GetPlots();
   for (auto &plot : plots) {
      TDirectory *branch = fOutput->mkdir(plot.first.c_str());
      branch->cd();
      auto hs = new THStack(plot.second.first->GetName(), plot.second.first->GetTitle());
      for (auto &hist : fStacksHists[plot.first.c_str()].first) {
         auto h = (TH1F *)hist->Clone();
         h->Write();
         hs->Add(h);
      }
      hs->Write(); // hstack
      fStacksHists[plot.first.c_str()].second->Write();
      // plot.second.second->Write();//Legend
   }
   //    fCut.Write("cuts");
   fOutput->Close();
}

//______________________________________________________________________________
void Plotter::Print()
{
   std::cout << "---------------- Chains ----------------" << std::endl;
   for (auto &chain : fChains) {
      std::cout << chain.first << std::endl;
      chain.second->Print();
   }
   std::cout << "---------------- HStacks ----------------" << std::endl;
   for (auto &hstack : fHStacks) {
      std::cout << hstack.first << std::endl;
      hstack.second.first->Print();
   }
}

//______________________________________________________________________________
std::vector<std::string> Plotter::Find(std::string path, std::string pattern)
{
   auto files = gSystem->GetFromPipe(Form("find %s -name \"%s\"", path.c_str(), pattern.c_str()));
   std::vector<std::string> strings;
   std::istringstream f(files.Data());
   std::string s;
   if (fVerbose) {
      std::cout << "---------------- ROOT Path/Files ----------------<<std::endl" << std::endl;
      std::cout << "Path = " << path << std::endl;
   }
   while (getline(f, s, '\n')) {
      if (fVerbose) {
         std::cout << "File = " << s << std::endl;
      }
      strings.push_back(s);
   }
   return strings;
}
