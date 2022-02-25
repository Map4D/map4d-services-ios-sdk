//
//  MFPlaceResult.h
//  Map4dServices
//
//  Created by Huy Dang on 12/28/21.
//

#ifndef MFResultPlace_h
#define MFResultPlace_h

#import "MFLocationComponent.h"

@protocol MFPlaceResult

@property(nonatomic, readonly, nullable) NSString *id;

@property(nonatomic, readonly, nonnull) NSString *name;

@property(nonatomic, readonly, nonnull) NSString *address;

@property(nonatomic, readonly, nonnull) MFLocationComponent *location;

@property(nonatomic, readonly, nonnull) NSArray<NSString *> *types;

@end


#endif /* MFResultPlace_h */
