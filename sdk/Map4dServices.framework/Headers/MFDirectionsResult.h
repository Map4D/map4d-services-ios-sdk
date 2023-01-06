//
//  MFDirectionsResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFDirectionsResult_h
#define MFDirectionsResult_h

#import "MFRouteResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFDirectionsResult : NSObject

@property(nonatomic, readonly, nullable) NSArray<MFRouteResult *> *routes;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFDirectionsResult_h */
