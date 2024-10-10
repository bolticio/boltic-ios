//
//  FyndUserDefaultsStorage.h
//  Analytics
//
//  Created by Tony Xiao on 8/24/16.
//  Copyright © 2016 Segment. All rights reserved.
//

@import Foundation;
#import "FyndStorage.h"

NS_SWIFT_NAME(FyndUserDefaultsStorage)
@interface FyndUserDefaultsStorage : NSObject <FyndStorage>

@property(nonatomic, strong, nullable) id<FyndCrypto> crypto;
@property(nonnull, nonatomic, readonly) NSUserDefaults *defaults;
@property(nullable, nonatomic, readonly) NSString *namespacePrefix;

- (instancetype _Nonnull)initWithDefaults:(NSUserDefaults *_Nonnull)defaults
                          namespacePrefix:(NSString *_Nullable)namespacePrefix
                                   crypto:(id<FyndCrypto> _Nullable)crypto;

@end
