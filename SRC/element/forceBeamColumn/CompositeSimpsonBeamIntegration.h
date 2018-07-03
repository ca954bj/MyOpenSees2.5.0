/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 1999, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** ****************************************************************** */

// $Revision$
// $Date$
// $Source$

#ifndef CompositeSimpsonBeamIntegration_h
#define CompositeSimpsonBeamIntegration_h

#include <BeamIntegration.h>

class Matrix;
class ElementalLoad;
class Channel;
class FEM_ObjectBroker;

class CompositeSimpsonBeamIntegration : public BeamIntegration
{
 public:
  CompositeSimpsonBeamIntegration();
  virtual ~CompositeSimpsonBeamIntegration();

  void getSectionLocations(int nIP, double L, double *xi);
  void getSectionWeights(int nIP, double L, double *wt);

  BeamIntegration *getCopy(void);

  // These two methods do nothing
  int sendSelf(int cTag, Channel &theChannel) {return 0;}
  int recvSelf(int cTag, Channel &theChannel,
	       FEM_ObjectBroker &theBroker) {return 0;}

  void Print(OPS_Stream &s, int flag = 0);  
};

#endif
