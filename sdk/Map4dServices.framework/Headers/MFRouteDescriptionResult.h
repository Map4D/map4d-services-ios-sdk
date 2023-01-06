//
//  MFRouteDescriptionResult.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFRouteDescriptionResult_h
#define MFRouteDescriptionResult_h

NS_ASSUME_NONNULL_BEGIN

@interface MFRouteDescriptionResult : NSObject

@property(nonatomic, readonly) NSString *text;
@property(nonatomic, readonly) double value;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* MFRouteDescriptionResult_h */
