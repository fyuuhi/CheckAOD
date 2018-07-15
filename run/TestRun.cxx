void TestRun (const int nEvents, const std::string& submitDir,const TString strInputFNDir,const std::string& strFilePattern)
{
  cout << "TestRun" << endl;
  //Set up the job for xAOD access:
  xAOD::Init().ignore();
  // create a new sample handler to describe the data files we use
  SH::SampleHandler sh;
  // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:
  const char* inputFilePath = gSystem->ExpandPathName (strInputFNDir);
  // const char* inputFilePath = gSystem->ExpandPathName ("/gpfs/fs2001/yfukuhar/data/youhei_Zmumu_AOD/Zmumu_noRpcHitWide/DIR_noRpcHitWide_user.yfukuhar.14514992.EXT0._000001.RDO.pool.root/");
  // const char* inputFilePath = gSystem->ExpandPathName ("/gpfs/fs2001/yfukuhar/data/youhei_Zmumu_AOD/Zmumu_noRpcHit/DIR_noRpcHit_user.yfukuhar.14514992.EXT0._000001.RDO.pool.root/");
  //SH::ScanDir().filePattern("AOD.*.*.pool.root.1").scan(sh,inputFilePath);
  // SH::ScanDir().filePattern("AOD.*.root").scan(sh,inputFilePath);
  cout << "Scan File" << endl;
  SH::ScanDir().filePattern(strFilePattern).scan(sh,inputFilePath);
  cout <<  "SH::ScanDir().filePattern(strInputFNDir.c_str()).scan(sh,inputFilePath)" << endl;
  // set the name of the tree in our files
  // in the xAOD the TTree containing the EDM containers is "CollectionTree"
  sh.setMetaString ("nc_tree", "CollectionTree");
  // print out the samples we found
  sh.print ();
  // this is the basic description of our job
  EL::Job job;
  job.sampleHandler (sh); // use SampleHandler in this job
  job.options()->setDouble (EL::Job::optMaxEvents,nEvents); // if -1 use all events
  // add our algorithm to the job
  MyAnalysisAlg *alg = new MyAnalysisAlg;
  // to abort unchecked status code ( kind of requirement on proper use of ANA_CHECK )
  xAOD::TReturnCode::enableFailure();
  // later on we'll add some configuration options for our algorithm that go here
  job.algsAdd (alg);
  //alg -> outputName = "myOutput";
  // make the driver we want to use:
  // this one works by running the algorithm directly:
  EL::DirectDriver driver;
  // process the job using the driver
  driver.submit (job, submitDir);
}
