//
//  MFDistanceMatrixElementResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFDistanceMatrixElementResult_h
#define MFDistanceMatrixElementResult_h

#import "MFRouteDescriptionResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFDistanceMatrixElementResult : NSObject

@property(nonatomic, readonly) MFRouteDescriptionResult *distance;
@property(nonatomic, readonly) MFRouteDescriptionResult *duration;
//@property(nonatomic, readonly, nullable) NSString *status;//TODO: check

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFDistanceMatrixElementResult_h */
