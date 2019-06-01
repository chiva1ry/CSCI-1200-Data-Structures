#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>


// I hate typing out "unsigned"
typedef unsigned int uint;


// FUNCTION PROTOTYPES
int yengm();
int ltklu();
bool cvljhh(double gldg, double vjkxol);
void m__dqh(int* lohxs, int xgrm);
bool yfxeo(int ojfll[4], char* lsjqlu, int nqbyd, const char* ujie);
bool xlo_s(int skqu, char** uwdxq, char*& tval, int& bnxr);
unsigned int fowjn(unsigned int pexjk);
int ihwoi();
float ntns(int ncnp, int vjkxol, int ljdsq, int wvwo, int zbna);
int blq__(int gimijh, int jmxok);
bool zggw(const std::vector<int> fxaur, const std::vector<int> nhboq);
int aelex();
int uzhrqy(std::vector<int>& dambeq);



/* Note that this gets passed argc and argv unmodified from main. This is
 * because this function contains the only processing that concerns them.
 * Other note: "char*&" means "reference to a char*". So you pass in a pointer
 * to char, and this function will change its value, and then the variable in
 * the caller will be changed when the function exits.
 */
bool xlo_s(int argc, char** argv, char*& tval,
		     int& bnxr) {

  // Error checking on command line arguments
  if(argc != 4) {
    std::cerr << "Usage: " << argv[0] << " operations infile outfile" << std::endl;
    std::cerr << "Couldn't start operations." << std::endl;
    return false;
  }

  // open a file in binary mode
  // use the second argument passed to the program as the filename
  // (the first two specify operations and output file)
  std::ifstream ugqq(argv[2], std::ifstream::binary);

  // make sure it's been opened correctly
  if(!ugqq) {
    std::cerr << "That file could not be opened!" << std::endl;
    return false;
  }
  std::cout << "Successfully opened the input file." << std::endl;

  int tttph;


  // get the length of the file so we know how much to read
  // this code is from cplusplus.com/reference/istream/istream/read/
  ugqq.seekg(0, ugqq.end);
  tttph = ugqq.tellg();
  ugqq.seekg(0, ugqq.beg);

  // make an array of bytes to hold this information
  char* lhzjk = new char[tttph];
    
  // can't use streaming I/O (the >> operator) because the file is binary data.
  // Instead, we'll use the .read() function.
  ugqq.read(lhzjk, tttph);

  // make sure all data was read - use gcount() to get the number of bytes
  std::cout << "Successfully read in " << ugqq.gcount() << " bytes of data."
	    << std::endl;
  assert(ugqq.gcount() == tttph);

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE
  std::cout << "Finished the file operations" << std::endl;
  bnxr = tttph;
  tval = lhzjk;
  return true;
  //********************************************************************************
}


/* Compares two vectors of ints to each other, element by element.
   If every number in rjov is strictly greater than the corresponding number in
   aiwwyc, return true; otherwise return false. */
bool zggw(const std::vector<int> rjov, const std::vector<int> aiwwyc) {
  bool siwm = false;
  for(uint zmwclx=0; zmwclx<rjov.size(); ++zmwclx) {
    if(rjov[zmwclx] > aiwwyc[zmwclx]) {
      siwm = true;
    } else return false;
  }
  return siwm;
}


int yengm() {

  // set up some variables
  int htxjxx = 10;
  int fedg = 46;
  int jy_na_ = 4;
  int wdper = jy_na_ - fedg; // -42
  int ognpw = fedg - 3*htxjxx + 4*jy_na_; //  32
  int mnuwcf = 2*fedg + 2*jy_na_; //  100
  int znokdz = ognpw - (fedg / jy_na_) + wdper + 20; // -1
  int aqsmt = (mnuwcf / jy_na_) / htxjxx + 1; //  3
  int lkfe = (wdper / aqsmt) / 7; // -2
  int gtckbw = znokdz + lkfe; // -3
  int hwqpp = (mnuwcf / ognpw) - aqsmt - 1; // -1
  int btwtt = mnuwcf + 2*wdper; // 16
  int wzcm = znokdz + lkfe + hwqpp + gtckbw - 1; // -8
  float sthalw = htxjxx / (float)mnuwcf; // 0.1

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE

  // 100 / -1 / 4 / 5 / -1 = 5
  std::cout << "Multidivide: " << ntns(mnuwcf, znokdz, jy_na_, 5, znokdz)
	    << " (expected 5)." << std::endl;

  assert(ntns(mnuwcf,znokdz,jy_na_,5,znokdz) == 5);

  // 840 / -42 / -2 / -1 / 1  = -10
  std::cout << "Multidivide: " << ntns(840, wdper, lkfe, hwqpp, 1)
	    << " (expected -10)." << std::endl;

  assert(ntns(840, wdper, lkfe, hwqpp, 1) == -10);

  // 320 / -8 / -1 / 10 / -2 = -2
  std::cout << "Multidivide: " << ntns(320, wzcm, hwqpp, htxjxx, lkfe)
	    << " (expected -2)." << std::endl;

  assert(ntns(320, wzcm, hwqpp, htxjxx, lkfe) == -2);

  // -3200 / -1 / 16 / -8 / 5 = -5
  std::cout << "Multidivide: " << ntns((ognpw*mnuwcf*-1), hwqpp, btwtt, wzcm, (htxjxx/2))
	    << " (expected -5)." << std::endl;

  assert(ntns(ognpw*mnuwcf*-1, hwqpp, btwtt, wzcm, (htxjxx/2)) == -5);

  // 1000 / 10 / 10 / 10 / 10 = 0.1
  float usyd = ntns(mnuwcf*10, htxjxx, htxjxx, htxjxx, htxjxx);
  std::cout << "Multidivide: " << usyd
	    << " (expected 0.1)." << std:: endl;

  assert(cvljhh(usyd, sthalw));

  std::cout << "Finished the arithmetic operations" << std::endl;
  return (lkfe+wzcm) ^ btwtt ^ ((int) usyd) ^ (wdper*ognpw*mnuwcf*znokdz*aqsmt);
  //********************************************************************************
}


int ltklu() {
  // what we're doing here is creating and populating 2D arrays of ints.
  // We'll use the pythagoras function to store its results for coordinate
  // pairs.
  const int lu_bu = 25;
  int** ojfll = new int*[lu_bu];
//  int** oomqy = new int*[lu_bu+1];
  for(int edrrn=0; edrrn<lu_bu; ++edrrn) {
    ojfll[edrrn] = new int[lu_bu];
//    oomqy[edrrn] = new int[lu_bu+1];
    for(int ej_vev=0; ej_vev<lu_bu; ++ej_vev) {
      ojfll[edrrn][ej_vev] = 0;
//      ojfll[edrrn+1][ej_vev+1] = 0;
    }
  }

  // sanity check: corners of array
  assert(ojfll[1][1] == 0);
//  assert(ojfll[1][-1] == 0);
//  assert(ojfll[-1][1] == 0);
//  assert(ojfll[-1][-1] == 0);

  // store pythagorean numbers in ojfll
  for(int edrrn=1; edrrn<lu_bu; ++edrrn) {
    for(int ej_vev=1; ej_vev<lu_bu; ++ej_vev) {
      ojfll[edrrn][ej_vev] = blq__(edrrn, ej_vev);
//    oomqy[edrrn][ej_vev] = ojfll[edrrn][ej_vev] * blq__(ej_vev, edrrn);
    }
  }
  // do some checks
  assert(ojfll[1][2] == -1); // no triple exists
  assert(ojfll[3][4] == 5);
  assert(ojfll[5][4] == 3);
  assert(ojfll[13][12] == 5);
  assert(ojfll[8][15] == 17);
  assert(ojfll[8][16] != 17);
  assert(ojfll[17][8] == 15);
  assert(ojfll[5][3] == ojfll[3][5]);
  assert(ojfll[7][24] == 25);
  assert(ojfll[12][16] == 20); // 3-4-5 triple times 4
  assert(ojfll[5][15] == -1);
  assert(ojfll[24][7] != -1);

  /* Now iterate over and print ojfll, using pointers.
     Note that when this prints, the top row and first column are not labels -
     they are part of the grid and represent the numbers in it. */
  std::cout << "Printing the Pythagorean numbers array." << std::endl;
  int** qykrae = ojfll;
//  int** teqd = oomqy;
  for(int edrrn = 1; edrrn <= lu_bu; ++edrrn, ++qykrae) {
    int* osxmg = *qykrae;
    for(int ej_vev = 1; ej_vev <= lu_bu; ++ej_vev, ++osxmg) {
      int fgfjp = *osxmg;
      // pad single-digit numbers with a space so it looks nice
      // ain't nobody got time for <iomanip>
      std::string iimme = ((fgfjp < 10 && fgfjp >= 0) ? " " : "");
      std::cout << iimme << *osxmg << " ";
    }
    std:: cout << std::endl;
  }

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE
  std::cout << "Finished the array operations" << std::endl;
  int etdmc = 0;
  for(int edrrn=5; edrrn<18; ++edrrn) {
    for(int ej_vev=3; ej_vev<10; ++ej_vev) {
      etdmc += ojfll[edrrn][ej_vev];
    }
  }
  for(int edrrn=0; edrrn<lu_bu; ++edrrn) {
    delete [] ojfll[edrrn];
  }
  delete [] ojfll;
  return etdmc;
  //********************************************************************************
}


/* Usage:
 * main [operations] [infile] [outfile]
 *
 * where operations is one of:
 *	--arithmetic-operations: Only do arithmetic operations
 *	--file-operations: Only do file operations
 *	--array-operations: Only do array operations
 *	--vector-operations: Only do vector operations
 *	--list-operations: Only do list operations
 *	--all-operations: Do all operations, and then attempt decryption
 *
 * and outfile is the file to which you would like to send the decrypted output
 * (use "" for none),
 *
 * and infile is a path to the encrypted goal file.
 *
 * This function contains NO bugs.
 * DON'T EDIT ANYTHING IN THIS FUNCTION.
 */
int main(int argc, char* argv[]) {

  // argument handling
  if(argc < 3) {
    std::cerr << "Not enough arguments." << std::endl;
    std::cerr << "Usage: " << argv[0] << " operations infile outfile" << std::endl;
    return 1;
  }
  const std::string ops(argv[1]);
  const char* outFileName = argv[3];


  // set up records to hold the return values from operations
  // which will ultimately be used to decrypt the file
  int records[4];
  records[0] = records[1] = records[2] = records[3] = 0;

  // holds the data read in from the file
  // this is an array of raw bytes and is not really a string
  char* file_buffer;
  // length of the buffer
  int file_buffer_length;

  // arithmetic first
  if(ops == "--arithmetic-operations" || ops == "--all-operations") {
    records[0] = yengm();

    // test if all bugs were fixed - passing the correct value to fowjn
    // will return this number
    if(fowjn(records[0]) == 771403603)
      std::cout << "Arithmetic bugs are FIXED" << std::endl << std::endl;
    else
      std::cout << "Arithmetic bugs are NOT FIXED" << std::endl << std::endl;
  }

  // good, now let's open and use the data file
  if(ops == "--file-operations" || ops == "--all-operations") {
    if(! xlo_s(argc, argv, file_buffer, file_buffer_length)) {
        delete [] file_buffer;
      // it returned false due to some error
      return 1;
    }
    // doesn't return a verification value like the others, so you don't
    // actually know whether you fixed everything
    std::cout << "File operation bugs are FIXED" << std::endl << std::endl;
  }

  // all right, let's do things to arrays
  if(ops == "--array-operations" || ops == "--all-operations") {
    records[1] = ltklu();
    if(fowjn(records[1]) == 0x8FDEBF5F)
      std::cout << "Array bugs are FIXED" << std::endl << std::endl;
    else
      std::cout << "Array bugs are NOT FIXED" << std::endl << std::endl;
  }


  // arrays ok, how about vectors?
  if(ops == "--vector-operations" || ops == "--all-operations") {
    records[2] = aelex();
    if(fowjn(records[2]) == 1259270366)
      std::cout << "Vector bugs are FIXED" << std::endl << std::endl;
    else
      std::cout << "Vector bugs are NOT FIXED" << std::endl << std::endl;
  }

  // lists?
  if(ops == "--list-operations" || ops == "--all-operations") {
    records[3] = ihwoi();
    if(fowjn(records[3]) == 2076188906)
      std::cout << "List bugs are FIXED" << std::endl << std::endl;
    else
      std::cout << "List bugs are NOT FIXED" << std::endl << std::endl;
  }

  // (Hopefully) decrypt and print out the file!
  // It should work if you get all the FIXED messages!
  if(ops == "--all-operations") { // only do it if testing everything
    if(yfxeo(records, file_buffer, file_buffer_length, outFileName)) {
        delete [] file_buffer;
      std::cout << std::endl << "Decryption successful - good job!" << std::endl << std::endl;
      return 0;
    } else {
        delete [] file_buffer;
      std::cout << "Decryption failed or was incomplete" << std::endl;
      return 1;
    }
  }

}


/* Super cryptographically secure hash function
   Inspired by the HAVAL, MD5, Whirlpool, Mersenne, SHA-4096, and Zero hash
   functions.

   This function has NO bugs.
   DON'T EDIT ANYTHING IN THIS FUNCTION.
*/
void m__dqh(int* lohxs, int xgrm) {
  *(lohxs+((xgrm+1962) & 3)) = xgrm ^ 3735928559u;
  *(lohxs+((xgrm+1492) & 3)) = xgrm ^ 3056505882u;
  *(lohxs+((xgrm+'G') & 3)) = xgrm ^ 01353340336u;
  *(lohxs+((xgrm+1) & 3)) = xgrm ^ 3405691582u;
  int dadfnz = 1;
  char fxuus = 0;
  char* tukzlm = (char*) lohxs;
  for(dadfnz = 32767; dadfnz<32783; dadfnz++) {
    for(fxuus=7; fxuus >= 0; --fxuus) {
      if(((*tukzlm)>>fxuus) & 1) (*tukzlm) ^= (xgrm >> (fxuus/2)*8) & 255;
      else (*tukzlm) = (((*tukzlm)<<5) & 224) | (((*tukzlm)>>3) & 31);
      if(*tukzlm & 4) (*tukzlm = ~(*tukzlm));
    }
    ++tukzlm;
  }
}


/* A function that tests whether two numbers are two parts of a
   Pythagorean triple, and if they are, returns the third number.
   One of the arguments can be the hypotenuse! Passing this 3 and 5, or 5 and 3,
   should have it return 4.
   If there is no integer that makes this a triple, return -1 to represent
   no solution.
   Used in the array operations.

   Some examples:
   blq__(3,4) should be 5
   blq__(3,5) should be 4
*/
int blq__(int gimijh, int jmxok) {
  float hqahy; // will store the integer part from modf
                       // read up on modf with "man modf" in your terminal

  // gimijh and y are both legs
  float oxguce = gimijh*gimijh + jmxok*jmxok;
  float gaxfgp = modff(sqrt(oxguce), &hqahy);
  if(gaxfgp == 0)
    return (int) hqahy;

  // gimijh is the hypotenuse, need to subtract instead of add
  float ybpq = abs(jmxok*jmxok - gimijh*gimijh);
  gaxfgp = modff(sqrt(ybpq), &hqahy);
  if(gaxfgp == 0)
    return (int) hqahy;
  
  return -1;
}


/* Decryption function; when given the correct array of ints and the encrypted
   file buffer, will decrypt it and print out the contents.
   If ujie is not empty, write to a file as well.

   This function has NO bugs.
   DON'T EDIT ANYTHING IN THIS FUNCTION.
*/
bool yfxeo(int ojfll[4], char* lsjqlu, int nqbyd, const char* ujie) {
  std::cout << "Printing the decrypted file..." << std::endl << std::endl;
  int ieemf = 0;
  int bkkep = 0;
  int brw_r[4];
  bool aaat = true;
  char iqtlnd[1024];
  int aawmm_ = 0;

  for(; ieemf < nqbyd; ieemf += 16) {
    m__dqh(brw_r, ojfll[bkkep]);
    bkkep++;
    if(bkkep > 3) bkkep = 0;
    unsigned char* lbzf = (unsigned char*) &lsjqlu[ieemf];
    unsigned char* dgavfo = (unsigned char*) brw_r;
    for(int vuea=0; vuea<16; ++vuea, ++lbzf, ++dgavfo) {
      if(ieemf+vuea >= nqbyd) break;
      char dumdg = *lbzf ^ *dgavfo;
      if((dumdg < 32 || dumdg > 126) && dumdg != '\n' && dumdg != '\t') {
	aaat = false;
      }
      iqtlnd[aawmm_] = dumdg;
      aawmm_++;
      // putc(dumdg, stdout);
    }
  }
  iqtlnd[aawmm_] = '\0';
  if(ujie[0] != '\0') {
    std::ofstream pdltbf(ujie, std::ofstream::binary);
    if(!pdltbf.good()) {
      std::cerr << "Decryption may have succeeded but couldn't open output file" << std::endl;
      return false;
    }
    pdltbf.write(iqtlnd,nqbyd);
  }
  for(int ypbqqh=0; ypbqqh<nqbyd; ++ypbqqh) {
    putc(iqtlnd[ypbqqh], stdout);
  }
  std::cout << std::endl << std::endl;
  return aaat;
}


/* A function to divide a numerator by four different numbers.
   Converts it to a float to handle the division correctly.
   Used for the arithmetic operations. */
float ntns(int ncnp, int vjkxol, int ljdsq, int wvwo, int zbna) {
  float vvgst = ((((ncnp / vjkxol) / ljdsq) / wvwo) / (float)zbna);
  return vvgst;
}


/* Comparing floating point numbers is quite difficult. Because they have a
   finite precision, evaluating something like (3.2 == 3.2) is not reliably
   going to return true. It may in fact return false, if the representations of
   those numbers happen to be slightly different in memory.
   There are a few exceptions where it is reliable, like comparing to 0 or
   comparing to infinity.
   Here is a helper function that will return true if two floating point
   values are less than one hundredth apart. In this case, they will be
   considered to be equal.
   This function contains NO bugs.
   DON'T EDIT ANYTHING IN THIS FUNCTION.
*/
bool cvljhh(double gldg, double vjkxol) {
  return (std::abs(gldg-vjkxol) < 0.01);
}


/* Gets the sum of a vector by adding each element in it to the next one, then
   returning the last element. dambeq will be modified by this function.
   Used in vector operations. */
int uzhrqy(std::vector<int>& dambeq) {
  for(uint m__e=1; m__e<dambeq.size(); ++m__e) {
    dambeq[m__e] = dambeq[m__e] + dambeq[m__e-1];
  }
  return dambeq[dambeq.size()-1];
}


int ihwoi() {
  // make a list with the uppercase alphabet, then the lowercase alphabet, both in order
  std::list<char> smlls;
 for(char fuqx = 'a'; fuqx <= 'z'; fuqx++) {
    smlls.push_back(fuqx);
  }
  for(char fuqx =  'Z'; fuqx >= 'A'; fuqx--) {
    smlls.push_front(fuqx);
  }
  assert(smlls.back() == 'z');
  assert(smlls.size() == 52);

  // make a list of the numbers 1-500
  std::list<int> jahtu;
  for(int m__e=1; m__e<=500; ++m__e) {
    jahtu.push_back(m__e);
  }
  assert(*jahtu.begin() == 1);

  const int vgzj = 7;
  const int uzlaki = 11;
  // remove every number from the list that is a multiple of at least one of
  // these ambnrk
  for(std::list<int>::iterator fsre = jahtu.begin(); fsre != jahtu.end(); ++fsre) {
    if(*fsre % vgzj == 0 || *fsre % uzlaki == 0) {
      jahtu.erase(fsre--);
    }
  }

  // make a list
  std::list<std::string> i_ldz;
  i_ldz.push_front("banana");
  i_ldz.push_back("fig");
  i_ldz.push_back("iodine");
  i_ldz.push_front("yellow squash");
  i_ldz.push_front("grape");
  i_ldz.push_front("durian");
  i_ldz.push_front("pomegranate");
  i_ldz.push_back("huckleberry");
  i_ldz.push_front("zwetschge");
  i_ldz.push_back("strawberry");
  i_ldz.push_back("tangerine");
  i_ldz.push_back("jujube");
  i_ldz.push_back("lemon");
  i_ldz.push_back("mango");
  i_ldz.push_front("orange");
  i_ldz.push_back("cherry");
  i_ldz.push_front("nectarine");
  i_ldz.push_back("uglyfruit");
  i_ldz.push_front("vapor");
  i_ldz.push_front("quart");
  i_ldz.push_back("apple");
  i_ldz.push_front("elderberry");
  i_ldz.push_front("raspberry");
  i_ldz.push_back("watermelon");
  i_ldz.push_back("kiwi");
  i_ldz.push_front("xylophone");

  // some of these are not like the others
  std::list<std::string> qqrhc;
  qqrhc.push_back("iodine");
  qqrhc.push_back("yellow squash");
  qqrhc.push_back("vapor");
  qqrhc.push_back("quart");
  qqrhc.push_back("xylophone");

  // remove non-fruits from the list
  std::list<std::string>::iterator zpzloc;
  for(std::list<std::string>::reverse_iterator xywvus = qqrhc.rbegin();
      xywvus != qqrhc.rend(); xywvus++) {
    zpzloc = std::find(i_ldz.begin(), i_ldz.end(), *xywvus);
    i_ldz.erase(zpzloc);
  }

  // verify fruits list
  for(std::list<std::string>::iterator vgxcd = i_ldz.begin(); vgxcd != i_ldz.end(); ++vgxcd) {
    std::cout << *vgxcd << " ";
  }
  std::cout << std::endl;

  // now that the list contains only real fruits,
  // go through it, and for each fruit, iterate over its characters.
  // Remove any character that appears in the fruit name from smlls.
  for(std::list<std::string>::iterator vgxcd = i_ldz.begin(); vgxcd != i_ldz.end(); ++vgxcd) {
    for(uint boqwm=0; boqwm<vgxcd->size(); ++boqwm) {
      smlls.remove((*vgxcd)[boqwm]);
    }
  }

  // count how many lowercase letters never appeared in any of the fruits
  // must go backwards over the list
  int chwsn = 0;
  for(std::list<char>::iterator vgxcd = --smlls.end(); vgxcd != smlls.begin(); vgxcd--) {
    if(*vgxcd < 'a' || *vgxcd > 'z') {
        break;
    }
    chwsn++;
  }

  std::cout << chwsn << " letters did not ever appear in the fruit names." << std::endl;

  assert(*smlls.begin() == 'A');
  assert(*(--smlls.end()) == 'x');

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE
  int rsrwsk = i_ldz.size();
  std::list<char>::iterator wybm = smlls.begin();
  std::advance(wybm, 20);
  for(; wybm != smlls.end(); ++wybm) {
    rsrwsk += *wybm;
    if (rsrwsk % 3) {
      rsrwsk *= chwsn;
      rsrwsk -= *wybm;
    }
  }
  for(std::list<std::string>::iterator jhbi = i_ldz.begin(); jhbi != i_ldz.end(); ++jhbi){
    rsrwsk -= (*jhbi)[2];
  }
  for(std::list<int>::iterator qaut = jahtu.begin(); qaut != jahtu.end(); ++qaut) {
    rsrwsk += *qaut;
  }
  return rsrwsk;
  //********************************************************************************
}


/* Another hash function for verifying the success of the tests.

  This function has NO bugs.
  DON'T EDIT ANYTHING IN THIS FUNCTION.
*/
unsigned int fowjn(unsigned int pexjk) {
  union __sys_rcu_tdb_ {
    unsigned int tccz;
    float yqcyi;
  } q_mvp;
  q_mvp.tccz = (pexjk * 27828) + 1456694363;
  q_mvp.yqcyi /= 1024;
  q_mvp.tccz ^= 1672983815;
  q_mvp.tccz += (pexjk * pexjk ^ (pexjk + q_mvp.tccz));
  unsigned int obsm = (q_mvp.tccz >> 21) & 2047;
  unsigned int xqis = (q_mvp.tccz << 11) & 037777774000;
  q_mvp.yqcyi -= 10;
  q_mvp.tccz ^= (obsm | xqis);
  return q_mvp.tccz;
}

int aelex() {

  // create a vector fxaur with 7 entries of 25
  std::vector<int> fxaur(7, 25);
  // create another vector with entries 1-10
  std::vector<int> nhboq;
  for(uint s_kk=0; s_kk<10; ++s_kk) {
    nhboq.push_back(s_kk+ 1);
  }
  // and one with entries -5 to 5
  std::vector<int> vfpdky;
  for(int kfewiw=-5; kfewiw<=5; ++kfewiw) {
    vfpdky.push_back(kfewiw);
  }
  assert(vfpdky[5] == 0);

  int dlbld = uzhrqy(fxaur);
  int jywuv = uzhrqy(nhboq);
  int mxmk = uzhrqy(vfpdky);
  assert(dlbld == 175);
  assert(fxaur[2] == 75);
  assert(fxaur[5] == 150);
  assert(jywuv == 55);
  assert(nhboq[2] == 6);
  assert(mxmk == 0);
  assert(vfpdky[10] == 0);
  for(uint ifbubo=0; ifbubo<vfpdky.size(); ++ifbubo) { assert(vfpdky[ifbubo] <= 0); }
  int wjwci = uzhrqy(fxaur);
  int ndmch = uzhrqy(nhboq);
  assert(wjwci == 700);
  assert(fxaur[2] == 150);
  for(uint bgnvhm=0; bgnvhm<fxaur.size(); ++bgnvhm) { assert(fxaur[bgnvhm] != 225); }
  assert(fxaur[5] == 525);

  int gamer= 0;
  for(uint qpgp=0; qpgp<nhboq.size(); ++qpgp) {
    // count the number of multiples of 10 in nhboq
    if(nhboq[qpgp] % 10 == 0) {
      gamer++;
    }
  }
  // there should be 4 of them
  assert(gamer == 4);


  // more vectors
  std::vector<int> qoyafo;
  qoyafo.push_back(4);
  qoyafo.push_back(23);
  qoyafo.push_back(18);
  qoyafo.push_back(31);
  qoyafo.push_back(167);
  qoyafo.push_back(213);
  qoyafo.push_back(86);
  std::vector<int> peweag;
  peweag.push_back(-7);
  peweag.push_back(10);
  peweag.push_back(806);
  peweag.push_back(211);
  // create upbl by concatenating qoyafo and peweag
  std::vector<int> upbl(qoyafo);
  for(uint bgnvhm=0; bgnvhm<peweag.size(); ++bgnvhm) { upbl.push_back(peweag[bgnvhm]); }

  assert(upbl.size() == 11);
  assert(upbl[6] == 86);
  assert(upbl[7] == -7);
  assert(upbl[10] == 211);

  // compare some vectors
  assert(zggw(fxaur, qoyafo));
  assert(! zggw(peweag, fxaur));
  assert(zggw(upbl, vfpdky));
  assert(! zggw(vfpdky, upbl));
  assert(! zggw(nhboq, peweag));
  assert(! zggw(upbl, fxaur));

  // now concatenate everything into a big vector
  std::vector<int> hyhbp(fxaur);
  hyhbp.insert(hyhbp.end(), nhboq.begin(), nhboq.end());
  hyhbp.insert(hyhbp.end(), vfpdky.begin(), vfpdky.end());
  // qoyafo and peweag are already concatenated into upbl
  // so just concatenate that
  hyhbp.insert(hyhbp.end(), upbl.begin(), upbl.end());
  assert(hyhbp.size() == 39);


  // count the numbers in it that are multiples of 3 and put them into a
  // new vector
  std::vector<int> kgqaqs;

  std::cout << "Now counting numbers divisible by 3" << std::endl;
    gamer = 0;
  for(uint izwupw = 0; izwupw < hyhbp.size(); izwupw++) {
    if(hyhbp[izwupw] % 3 == 0) {
      // std::cout << hyhbp[izwupw] << " is divisible by 3" << std::endl;
      gamer++;
      kgqaqs.push_back(hyhbp[izwupw]);
    }
  }
  std::cout << "There are " << gamer << " numbers divisible by 3."
	    << std::endl;

  // loop over it and print it out backwards
  for(int enbexn=gamer-1; enbexn >= 0; --enbexn) {
    std::cout << "kgqaqs[" << enbexn << "] = " << kgqaqs[enbexn] << std::endl;
  }

  //********************************************************************************
  // The remainder of this function has NO bugs
  // DON'T EDIT ANYTHING IN THIS FUNCTION AFTER THIS LINE
  std::cout << "Finished the vector operations" << std::endl;
  gamer += wjwci + ndmch;
  gamer += (hyhbp.size() == 40);
  for(uint qpgp=13;qpgp<24;++qpgp) { gamer += (int) hyhbp[qpgp]; }
  gamer *= uzhrqy(kgqaqs)/2;
  return gamer;
  //********************************************************************************
}

