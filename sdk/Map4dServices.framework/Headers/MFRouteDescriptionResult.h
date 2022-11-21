//
//  MFRouteDescriptionResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/29/21.
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
