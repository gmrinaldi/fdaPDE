#ifndef ROBJECTS_H
#define ROBJECTS_H


class RNumericMatrix{
public:

	RNumericMatrix(const Real * const matr, const UInt nrows, const UInt ncols) :
		matr_(matr), nrows_(nrows), ncols_(ncols) {}

	#ifdef R_VERSION_
	RNumericMatrix(SEXP matr) : 
		matr_(REAL(matr)), 
			nrows_(INTEGER(Rf_getAttrib(matr, R_DimSymbol))[0]), 
				ncols_(INTEGER(Rf_getAttrib(matr, R_DimSymbol))[1]) {}
	#endif

	const Real& operator()(UInt i, UInt j) const {return matr_[i+nrows_*j];}
	const Real& operator[](UInt i) const {return matr_[i];}

	const UInt& nrows() const {return nrows_;}
	const UInt& ncols() const {return ncols_;}

private:
	const Real * const matr_;
	const UInt nrows_;
	const UInt ncols_;

};

class RIntegerMatrix{
public:

	RIntegerMatrix(const UInt * const matr, const UInt nrows, const UInt ncols) :
		matr_(matr), nrows_(nrows), ncols_(ncols) {}


	#ifdef R_VERSION_
	RIntegerMatrix(SEXP matr) : 
		matr_(INTEGER(matr)), 
			nrows_(INTEGER(Rf_getAttrib(matr, R_DimSymbol))[0]), 
				ncols_(INTEGER(Rf_getAttrib(matr, R_DimSymbol))[1]) {}
	#endif

	const UInt& operator()(UInt i, UInt j) const {return matr_[i+nrows_*j];}
	const UInt& operator[](UInt i) const {return matr_[i];}

	const UInt& nrows() const {return nrows_;}
	const UInt& ncols() const {return ncols_;}

private:
	const UInt * const matr_;
	const UInt nrows_;
	const UInt ncols_;

};

#endif 
