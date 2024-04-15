// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GALAGA_USFX_LAB01/MovimientoNaves.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovimientoNaves() {}
// Cross Module References
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_UMovimientoNaves_NoRegister();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_UMovimientoNaves();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_GALAGA_USFX_LAB01();
// End Cross Module References
	void UMovimientoNaves::StaticRegisterNativesUMovimientoNaves()
	{
	}
	UClass* Z_Construct_UClass_UMovimientoNaves_NoRegister()
	{
		return UMovimientoNaves::StaticClass();
	}
	struct Z_Construct_UClass_UMovimientoNaves_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovimientoNaves_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_GALAGA_USFX_LAB01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovimientoNaves_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MovimientoNaves.h" },
		{ "ModuleRelativePath", "MovimientoNaves.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovimientoNaves_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovimientoNaves>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMovimientoNaves_Statics::ClassParams = {
		&UMovimientoNaves::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMovimientoNaves_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovimientoNaves_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovimientoNaves()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMovimientoNaves_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMovimientoNaves, 2384670216);
	template<> GALAGA_USFX_LAB01_API UClass* StaticClass<UMovimientoNaves>()
	{
		return UMovimientoNaves::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMovimientoNaves(Z_Construct_UClass_UMovimientoNaves, &UMovimientoNaves::StaticClass, TEXT("/Script/GALAGA_USFX_LAB01"), TEXT("UMovimientoNaves"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovimientoNaves);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
