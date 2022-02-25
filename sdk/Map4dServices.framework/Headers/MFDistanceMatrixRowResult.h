//
//  MFDistanceMatrixRowResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
//

#ifndef MFDistanceMatrixRowResult_h
#define MFDistanceMatrixRowResult_h

#import "MFDistanceMatrixElementResult.h"

@protocol MFDistanceMatrixRowResult

@property(nonatomic, readonly, nullable) NSArray<id<MFDistanceMatrixElementResult>> *elements;

@end

#endif /* MFDistanceMatrixRowResult_h */
