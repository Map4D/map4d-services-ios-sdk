//
//  MFDirectionsResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/29/21.
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
