void test_w() {
    TFile f("test.root","recreate");
    TTree *t1 = new TTree("t1","test tree");
    const Int_t n = 1000;
    Int_t a[n];
    Double_t b;
    t1->Branch("a",a,"a/I");
    t1->Branch("b",&b,"b/D");
    for (Int_t i1 = 0;i1<10000;i1++) {
        Int_t temp = 0;
        for (Int_t i2 = 0;i2<n;i2++) {
            a[i2] = (Int_t)(0.5 + gRandom->Uniform(0.5,6.5));
            temp += a[i2];
        }
        b = (Double_t)temp / (Double_t)n;
        t1->Fill();
    }
    t1->Write();
}
void test_r() {
    TFile *f = new TFile("test.root");
    TTree *t2 = (TTree*)f->Get("t1");
    Double_t c;
    t2->SetBranchAddress("b",&c);
    TH1F *h = new TH1F("h","central limit theorem",10000,1,6);
    Int_t nentries = (Int_t)t2->GetEntries();
    for (Int_t i = 0;i<nentries;i++) {
        t2->GetEntry(i);
        h->Fill(c);
    }
    h->Draw();
}
void test() {
    test_w();
    test_r();
}
