//
//  MFDistanceMatrixResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFDistanceMatrixResult_h
#define MFDistanceMatrixResult_h

#import <CoreLocation/CoreLocation.h>
#import "MFDistanceMatrixRowResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFDistanceMatrixResult : NSObject

//TODO: address
//@property(nonatomic, readonly, nonnull) NSArray<CLLocation *> *originAddresses
//@property(nonatomic, readonly, nonnull) NSArray<CLLocation *> *destinationAddresses
@property(nonatomic, readonly, nullable) NSArray<MFDistanceMatrixRowResult *> *rows; /* routeRows */

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFDistanceMatrixResult_h */
