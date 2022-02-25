//
//  MFRequestParams.h
//  Map4dServices
//
//  Created by Huy Dang on 12/30/21.
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
