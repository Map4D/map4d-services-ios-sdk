//
//  MFSuggestionResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/23/21.
//

#ifndef MFSuggestionResult_h
#define MFSuggestionResult_h

#import "MFLocationComponent.h"

@protocol MFSuggestionResult

@property(nonatomic, readonly, nullable) NSString *id;

@property(nonatomic, readonly, nonnull) NSString *name;

@property(nonatomic, readonly, nonnull) NSString *address;

@property(nonatomic, readonly, nonnull) MFLocationComponent *location;

@property(nonatomic, readonly, nonnull) NSArray<NSString *> *types;

@end

#endif /* MFSuggestionResult_h */
