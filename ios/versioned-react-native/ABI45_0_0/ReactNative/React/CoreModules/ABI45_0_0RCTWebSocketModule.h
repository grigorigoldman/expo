/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI45_0_0React/ABI45_0_0RCTEventEmitter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ABI45_0_0RCTWebSocketContentHandler <NSObject>

- (id)processWebsocketMessage:(id __nullable)message
                  forSocketID:(NSNumber *)socketID
                     withType:(NSString *__nonnull __autoreleasing *__nonnull)type;

@end

@interface ABI45_0_0RCTWebSocketModule : ABI45_0_0RCTEventEmitter

// Register a custom handler for a specific websocket. The handler will be strongly held by the WebSocketModule.
- (void)setContentHandler:(id<ABI45_0_0RCTWebSocketContentHandler> __nullable)handler forSocketID:(NSNumber *)socketID;

- (void)sendData:(NSData *)data forSocketID:(nonnull NSNumber *)socketID;

@end

@interface ABI45_0_0RCTBridge (ABI45_0_0RCTWebSocketModule)

- (ABI45_0_0RCTWebSocketModule *)webSocketModule;

@end

NS_ASSUME_NONNULL_END
