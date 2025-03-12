//
//  MFRequestParams.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
//

#ifndef MFRequestParams_h
#define MFRequestParams_h

#import <Foundation/Foundation.h>

@protocol MFRequestParams

/* For GET request */
- (NSArray<NSURLQueryItem *> *)asQueryItems;

/* For POST request */
- (NSDictionary<NSString *, NSObject *> *)asRequestBody;

@end

#endif /* MFServiceParams_h */
