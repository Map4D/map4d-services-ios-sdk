//
//  MFDistanceMatrixResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
//

#ifndef MFDistanceMatrixResult_h
#define MFDistanceMatrixResult_h

#import <CoreLocation/CoreLocation.h>
#import "MFDistanceMatrixRowResult.h"

@protocol MFDistanceMatrixResult

//TODO: address
//@property(nonatomic, readonly, nonnull) NSArray<CLLocation *> *originAddresses
//@property(nonatomic, readonly, nonnull) NSArray<CLLocation *> *destinationAddresses
@property(nonatomic, readonly, nullable) NSArray<id<MFDistanceMatrixRowResult>> *rows; /* routeRows */

@end

#endif /* MFDistanceMatrixResult_h */
