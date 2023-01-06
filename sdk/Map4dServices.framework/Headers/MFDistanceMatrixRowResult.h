//
//  MFDistanceMatrixRowResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFDistanceMatrixRowResult_h
#define MFDistanceMatrixRowResult_h

#import "MFDistanceMatrixElementResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFDistanceMatrixRowResult : NSObject

@property(nonatomic, readonly, nullable) NSArray<MFDistanceMatrixElementResult *> *elements;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFDistanceMatrixRowResult_h */
