//
//  MFServiceError.h
//  Map4dServices SDK for iOS
//
//  Copyright (c) 2022 IOTLink LLC.
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
