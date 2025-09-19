//
//  MFPlaceResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFResultPlace_h
#define MFResultPlace_h

#import "MFLocationComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFPlaceResult : NSObject

@property(nonatomic, readonly, nullable) NSString *id;

@property(nonatomic, readonly) NSString *name;

@property(nonatomic, readonly) NSString *address;

@property(nonatomic, readonly) NSString *oldAddress;

@property(nonatomic, readonly) MFLocationComponent *location;

@property(nonatomic, readonly) NSArray<NSString *> *types;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFResultPlace_h */
