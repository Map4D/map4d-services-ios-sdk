//
//  MFDistanceMatrixElementResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
//

#ifndef MFDistanceMatrixElementResult_h
#define MFDistanceMatrixElementResult_h

#import "MFRouteDescriptionResult.h"

@protocol MFDistanceMatrixElementResult

@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> distance;
@property(nonatomic, readonly, nonnull) id<MFRouteDescriptionResult> duration;
//@property(nonatomic, readonly, nullable) NSString *status;//TODO: check

@end


#endif /* MFDistanceMatrixElementResult_h */
