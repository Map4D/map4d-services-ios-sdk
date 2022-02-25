//
//  MFServiceError.h
//  Map4dServices
//
//  Created by Huy Dang on 12/21/21.
//

#ifndef MFServiceError_h
#define MFServiceError_h

#import <Foundation/Foundation.h>

@protocol MFServiceError

@property (readonly, nonnull) NSString* code;
@property (readonly, nonnull) NSString* message;
@property (readonly, nullable) NSError* error;

@end


#endif /* MFServiceError_h */
