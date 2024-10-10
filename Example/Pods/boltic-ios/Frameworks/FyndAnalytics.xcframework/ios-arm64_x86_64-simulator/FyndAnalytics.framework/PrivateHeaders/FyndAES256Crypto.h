//
//  FyndAES256Crypto.h
//  Analytics
//
//  Copyright © 2016 Segment. All rights reserved.
//

@import Foundation;
#import "FyndCrypto.h"

NS_SWIFT_NAME(FyndAES256Crypto)
@interface FyndAES256Crypto : NSObject <FyndCrypto>

@property(nonatomic, readonly, nonnull) NSString *password;
@property(nonatomic, readonly, nonnull) NSData *salt;
@property(nonatomic, readonly, nonnull) NSData *iv;

- (instancetype _Nonnull)initWithPassword:(NSString *_Nonnull)password
                                     salt:(NSData *_Nonnull)salt
                                       iv:(NSData *_Nonnull)iv;
// Convenient shorthand. Will randomly generate salt and iv.
- (instancetype _Nonnull)initWithPassword:(NSString *_Nonnull)password;

+ (NSData *_Nonnull)randomDataOfLength:(size_t)length;

@end
