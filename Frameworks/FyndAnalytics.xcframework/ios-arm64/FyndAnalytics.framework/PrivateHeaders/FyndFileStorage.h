//
//  FyndFileStorage.h
//  Analytics
//
//  Copyright © 2016 Segment. All rights reserved.
//

@import Foundation;
#import "FyndStorage.h"

NS_SWIFT_NAME(FyndFileStorage)
@interface FyndFileStorage : NSObject <FyndStorage>

@property(nonatomic, strong, nullable) id<FyndCrypto> crypto;

- (instancetype _Nonnull)initWithFolder:(NSURL *_Nonnull)folderURL
                                 crypto:(id<FyndCrypto> _Nullable)crypto;

- (NSURL *_Nonnull)urlForKey:(NSString *_Nonnull)key;

+ (NSURL *_Nullable)applicationSupportDirectoryURL;
+ (NSURL *_Nullable)cachesDirectoryURL;

@end
