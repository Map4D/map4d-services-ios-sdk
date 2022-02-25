//
//  MFDirectionsResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/29/21.
//

#ifndef MFDirectionsResult_h
#define MFDirectionsResult_h

#import "MFRouteResult.h"

@protocol MFDirectionsResult

@property(nonatomic, readonly, nullable) NSArray<id<MFRouteResult>> *routes;

@end

#endif /* MFDirectionsResult_h */
